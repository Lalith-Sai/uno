#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Cards {
        std::vector<int> cardHand;
        std::vector<char> cardColor;
    public:
        Cards();
        int returnCard(int i) {
            return cardHand.at(i);
        }
        char returnColor(int i) {
            return cardColor.at(i);
        }
};




class Player: public Cards {
        // Player score, highest no of cards
    public:
        Player();
        void DisplayCards();
              
};



Cards::Cards() {
    srand (time(NULL));
    for (int i = 0; i  < 7; i++) {
        cardHand.push_back(rand() % 12 + 1);   
        int tempVal = rand() % 4 + 1;
        if (tempVal == 1) {
            cardColor.push_back('R');
        }
        else if (tempVal == 2) {
            cardColor.push_back('B');
        }
        else if (tempVal == 3) {
            cardColor.push_back('G');
        }
        else {
            cardColor.push_back('Y');
        }
    }
}




Player::Player() {
    
}
void Player::DisplayCards() {
    for (int i = 0; i < 7; i++) {
        int tempVal = returnCard(i);
        std::string color;

        if (returnColor(i) == 'R') {
            color.append("\x1b[31m");
        }
        else if (returnColor(i) == 'B') {
            color.append("\x1b[34m");
        }
        else if (returnColor(i) == 'G') {
            color.append("\x1b[32m");
        }
        else if (returnColor(i) == 'Y') {
            color.append("\x1b[33m");
        }

        std::cout << color + "--------------" << std::endl;
            for (int j = 0; j < 8; j++) {
                if (j != 4)
                    std::cout << "|            |" << std::endl;
                else {      
                    std::cout << "|     " << tempVal;
                    if (tempVal >= 10) {
                        std::cout <<  "     |" << std::endl;
                    } 
                    else {
                        std::cout <<  "      |" << std::endl;
                    }
                } 
            }
        std::cout << "--------------" << std::endl;;   
    } 
    std::cout << "\x1b[0m@@@";
}
