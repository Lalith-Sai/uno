#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stack>


class Card {
        char color;
        int number;
    public:    
        Card() {
            getRandomCard();
        }

        void getRandomCard() {

            number = rand() % 12 + 1;

            int tempVal = rand() % 4 + 1;
            switch (tempVal) {
                case 1: color = 'R';
                        break;
                case 2: color = 'B';
                        break;
                case 3: color = 'G';
                        break;
                case 4: color = 'Y';
                        break;
            }
        }
        void DisplayCard();
};


class Deck {
        std::vector<Card*> cardHand;
    public:
        void Init() {
            cardHand.resize(7);
            for (int i = 0; i < 7; i++) {
                cardHand[i] = new Card();
            }
        }
        void Display();     
};

class Player {
        // Player score, highest no of cards, stats
        Deck deck;
        int highestNumCards;
    public:
        void InitDeck() { 
            deck.Init();
            highestNumCards = 7;
        }

        void DisplayDeck();
              
};

//------------- FUNCTIONS ---------------

void Card::DisplayCard() {
    std::string display = "";
    if (color == 'R') {
        display.append("\x1b[31m");
    }
    else if (color == 'B') {
            display.append("\x1b[34m");
    }
    else if (color == 'G') {
        display.append("\x1b[32m");
    }
    else if (color == 'Y') {
        display.append("\x1b[33m");
    }

    if (number >= 10) {
        display.append("\x1b[0m");
    }
    std::cout << display + "--------------" << std::endl;
    for (int j = 0; j < 8; j++) {
        if (j != 4)
            std::cout << "|            |" << std::endl;
        else {      
            if (number == 10) {
                std::cout <<  "|     +2     |" << std::endl;
            }
            else if (number == 11) {
                std::cout <<  "|     +4     |" << std::endl;
            }
            else if (number == 12) {
                std::cout <<  "|Color change|" << std::endl;
            }        
            else {
                std::cout <<  "|     " << number << "      |" << std::endl;
                }
        } 
    }
    std::cout << "--------------" << std::endl;;   
     
    std::cout << "\x1b[0m";
}

void Deck::Display() {
    for (int i = 0; i < cardHand.size(); i++) {
        cardHand[i]->DisplayCard();
    }
}

void Player::DisplayDeck() {
    deck.Display();
}
