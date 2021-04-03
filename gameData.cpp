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
        std::cout << "--------------" << std::endl;
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
    std::cout << "@#";
}
