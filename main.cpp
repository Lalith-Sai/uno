#include "gameData.h"

void displayHand(Player player) {
    player.DisplayHand();
}

bool isValidCard(Card* placedCard, std::vector<Card*> deck) {
    //Deck is empty at the start of game
    if (deck.size() == 0)
        return true;

    //Special cards have no restrictions
    if (placedCard->getNumber() > 10)
        return true;

    Card* topCard = deck.back();

    //+2 Card needs to match the color
    if (placedCard->getNumber() == 10) {
        if (placedCard->getColor() == topCard->getColor()) 
            return true;
    }
    
    
    //Check if card is valid to place according to uno's rule
    if (placedCard->getColor() == topCard->getColor() || placedCard->getNumber() == topCard->getNumber()) 
        return true;
    
    return false;
}

void displayDeckTop(std::vector<Card*> deck) {
    std::cout << "Deck: " << std::endl;
    deck.back()->DisplayCard();
}

void changeDeckColor(std::vector<Card*>& deck) {
    std::cout << "Color change! Pick the color you want to set: ";
    char color;
    std::cin >> color;
    if (color == 'R' || color == 'G' || color == 'Y' || color == 'B') {
        deck.back()->assignColor(color);
    }
    else {
        std::cout << "\nInvalid color, enter only first letter of color!" << std::endl;
        changeDeckColor(deck);
        return;
    }
    
}

void placeCard(Player& player, std::vector<Card*>& deck) {
    std::string cardVal;
    
    std::cout << "\nEnter card to place(Number/Color), Type 'new' if you don't have a valid card,";
    std::cout << "\n'+2(color)', '+4' or 'CC' (color change) for special cards: ";
    std::cin >> cardVal;
    if (cardVal == "new") {

        //Get new card and display new hand
        player.GetNewCard();
        player.DisplayHand();
        displayDeckTop(deck);
        placeCard(player, deck);

        return;
    }

    Card* placedCard = player.FindCard(cardVal);
    
    if (placedCard == NULL) {
        std::cout << "\nInvalid input, Try again.";
 
        //Player re-enter value again
        placeCard(player, deck);
        return;
    }
    
    if (isValidCard(placedCard, deck)) {
        std::cout << "You placed: " << std::endl;
        placedCard->DisplayCard();
        deck.push_back(placedCard);
        player.DeleteCard(placedCard);

        //Special card prompts
        
        //+2 card
        if (placedCard->getNumber() == PLUS_TWO)
            std::cout << "You added a +2 card!, Next player gets 2 additional cards" << std::endl;
        else if (placedCard->getNumber() == PLUS_FOUR) {
            std::cout << "You added a +4 card!, Next player gets 4 additional cards" << std::endl;
            changeDeckColor(deck);
        }
        else if (placedCard->getNumber() == COLOR_CHANGE) {
            changeDeckColor(deck);
        }



        //Pause to review the card placed 
        std::cout << "Press Q to pass to the next player: ";
        std::cin >> cardVal;
    }
    else {
        std::cout << "Card does not fit in deck, Try again.";
        
        //Player re-enter value again
        placeCard(player, deck);
        return;
    }
}

void checkGameStatus(Player playerOne, Player playerTwo) {
    if (playerOne.GetNumCards() <= 0) {
        std::cout << "PLAYER 1 WINS!!!" << std::endl;
        exit(EXIT_SUCCESS);
    }
    else if (playerTwo.GetNumCards() <= 0) {
        std::cout << "PLAYER 2 WINS!!!" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void addSpecialCards(Player& playerOne, Player& playerTwo, bool playerOneTurn, std::vector<Card*>& deck) {
    Card* topCard = deck.back();
    int count = 0;

    if (topCard->getNumber() == PLUS_TWO) {
        std::cout << "Ouch! You just got a +2 penalty" << std::endl;
        count = 2;
    }
    else if (topCard->getNumber() == PLUS_FOUR) {
        std::cout << "Ouch! You just got a +4 penalty" << std::endl;
        count = 4;
    }
    else {
        return;
    }

    //Add penalty cards to players
    if (playerOneTurn) {
        for (int i = 0; i < count; i++) {
        playerOne.GetNewCard();
        }
    }
    else {
        for (int i = 0; i < count; i++) {
        playerTwo.GetNewCard();
        }
    }

}

int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tempVal;

    Player playerOne;
    Player playerTwo;

    //Card deck
    std::vector<Card*> deck;

    //Init unique hands for both players
    srand(time(NULL));
    playerOne.InitHand();
    srand(time(NULL) * 2);
    playerTwo.InitHand();

    do {
        system("clear");
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;

        //Display last placed card
        if (deck.size() > 0) {
            displayDeckTop(deck);
            addSpecialCards(playerOne, playerTwo, playerOneTurn, deck);
        }

        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerOne);
                placeCard(playerOne, deck);
            } else {
                continue;
            }

            playerOneTurn = false;
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerTwo);
                placeCard(playerTwo, deck);
            } else {
                continue;
            }

            playerOneTurn = true;
        }
        checkGameStatus(playerOne, playerTwo);

    }while (gameProgress);
    
    return 0;
}
