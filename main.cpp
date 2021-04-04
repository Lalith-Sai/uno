#include <iostream>
#include "gameData.cpp"


void displayHand(Player player) {
    player.DisplayCards();
}

void placeCard(Player player) {
    int tempVal;
    std::cout << "\n\n Enter card number to place: ";
    std::cin >> tempVal;
    //Accept card input and place deck
}


int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tmpVal;

    Player playerOne;
    Player playerTwo;

    do {
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;
        
        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND" << std::endl;
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerOne);
                placeCard(playerOne);
            }

            gameProgress = false;
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND" << std::endl;
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerTwo);
                placeCard(playerTwo);
            }
        }

    }while (gameProgress);
    
    


    return 0;
}