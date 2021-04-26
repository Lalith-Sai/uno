#include <iostream>
#include "gameData.cpp"


void displayHand(Player player) {
    player.DisplayCards();
}

void placeCard(Player player, Deck card) {
    int tempVal;
    std::cout << "\n\nEnter card number to place: ";
    std::cin >> tempVal;
    //ERROR: CANNOT INPUT CHARACTER VARIABLE - SEGMATION FAULT
    for (int i = 0; i < player.returnCardHand().size(); i++) {
        if (player.returnCardHand().at(i) == tempVal) {
            card.PlaceCard(player.returnCard(i), player.returnColor(i));
            card.Display();
            break;
        }
        else if (i == player.returnCardHand().size() - 1) {
            std::cout << "ERROR: Enter correct value.";
            placeCard(player, card);
        }
    }

}

void showDeck() {
    std::cout << "--DECK--" << std::endl;
}


int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tmpVal;

    Player playerOne;
    Player playerTwo;
    Deck card;

    do {
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;
        
        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerOne);
                showDeck();
                placeCard(playerOne, card);
            }

            gameProgress = false;
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerTwo);
                showDeck();
                placeCard(playerTwo, card);
            }
        }

    }while (gameProgress);
    
    
    return 0;
}