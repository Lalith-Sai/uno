#include <iostream>
#include "gameData.cpp"


void displayHand(Player player) {
    player.DisplayCards();
}

void showDeck(Deck card) {
    std::cout << "--DECK--" << std::endl;
    card.DisplayTopCard();
}

void placeCard(Player player, Deck card) {
    int tempVal;
    std::cout << "\n\nEnter card number to place: ";
    std::cin >> tempVal;
    //ERROR: CANNOT INPUT CHARACTER VARIABLE - SEGMATION FAULT
    for (int i = 0; i < player.returnCardHand().size(); i++) {
        if (player.returnCardHand().at(i) == tempVal) {
            card.PlaceCard(player.returnCard(i), player.returnColor(i));
            std::cout << "You played: " << std::endl;
            showDeck(card);
            break;
        }
        else if (i == player.returnCardHand().size() - 1) {
            std::cout << "ERROR: Enter correct value." << std::endl;
            placeCard(player, card);
        }
    }

}




int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tempVal;

    Player playerOne;
    Player playerTwo;
    Deck card;

    do {
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;
        
        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerOne);
                showDeck(card);
                placeCard(playerOne, card);
            }

            gameProgress = false;
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerTwo);
                showDeck(card);
                placeCard(playerTwo, card);
            }
        }

    }while (gameProgress);
    
    
    return 0;
}