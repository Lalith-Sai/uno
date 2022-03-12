#include "gameData.cpp"


void displayHand(Player player) {
    player.DisplayDeck();
}

void placeCard(Player player) {
    int tempVal;
    std::cout << "\n\nEnter card number to place: ";

}

int main() {
    bool gameProgress = true;
    bool playerOneTurn = true;
    char tempVal;

    Player playerOne;
    Player playerTwo;
    
    srand(time(NULL) * 1);
    playerOne.InitDeck();
    srand(time(NULL) * 2);
    playerTwo.InitDeck();

    do {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "          Uno         " << std::endl;
        std::cout << "----------------------" << std::endl;
        
        if (playerOneTurn) {
            std::cout << "PLAYER 1 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerOne);
                std::cin >> tempVal;
                //placeCard(playerOne);
            }

            playerOneTurn = false;
        }
        else {
            std::cout << "PLAYER 2 - PRESS Q TO VIEW YOUR HAND: ";
            std::cin >> tempVal;

            if (tempVal == 'Q') {
                displayHand(playerTwo);
                std::cin >> tempVal;

            }
            playerOneTurn = true;
        }

    }while (gameProgress);
    
    
    return 0;
}