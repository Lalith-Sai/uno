#include <iostream>
#include "gameData.cpp"


void displayHand(Player player) {
    player.DisplayCards();
}



int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tmpVal;

    Player playerOne;
    Player playerTwo;

    while (gameProgress) {
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;
        
        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND" << std::endl;
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerOne);
            }
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND" << std::endl;
            std::cin >> tmpVal;

            if (tmpVal == 'Q') {
                displayHand(playerTwo);
            }
        }

    }
    
    


    return 0;
}