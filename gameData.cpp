#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Cards {
        std::vector<int> cardHand;
    public:
        Cards() {
            srand (time(NULL));
            for (int i = 0; i  < 7; i++) {
                cardHand.push_back(rand() % 12 + 1);   
            }
        }
        int returnCard(int i) {
            return cardHand.at(i);
        }
};




class Player: public Cards {
        
    public:
        Player();
        void DisplayCards();
              
};



Player::Player() {
    
}
void Player::DisplayCards() {
    for (int i = 0; i < 7; i++) {
        int tempVal = returnCard(i);
        
        std::cout << "--------------\n";
            for (int j = 0; j < 8; j++) {
                    if (j != 4)
                        std::cout << "|            |\n";
                    else {      
                        std::cout << "|     " << tempVal;
                        if (tempVal >= 10) {
                            std::cout <<  "     |\n";
                        } else {
                            std::cout <<  "      |\n";
                        }
                    } 
            }
        std::cout << "--------------\n";   
    }
    std::cout << "@#";
}
