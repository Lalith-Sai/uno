#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Cards {
        std::vector<int> cardHand;
        std::vector<char> cardColor;
    public:
        Cards();
        std::vector<int> returnCardHand() {
            return cardHand;
        }
        int returnCard(int i) {
            return cardHand.at(i);
        }
        char returnColor(int i) {
            return cardColor.at(i);
        }
};

class Player: public Cards {
        // Player score, highest no of cards, stats
    public:
        Player();
        void DisplayCards();
              
};

//------------- Card deck Linked list -------------

struct node {
    int cardNumber;
    char cardColor;
    node *next;
};

class Deck {
    node *head, *tail;
    public:
        Deck() {
            head = NULL;
            tail = NULL;
        }
        void PlaceCard(int a, int b);
        void Display() {
            std::cout << head->cardNumber;
        }
};

//------------- FUNCTIONS ---------------

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

        if (tempVal >= 10) {
            color.append("\x1b[0m");
        }
        std::cout << color + "--------------" << std::endl;
            for (int j = 0; j < 8; j++) {
                if (j != 4)
                    std::cout << "|            |" << std::endl;
                else {      
                    if (tempVal == 10) {
                        std::cout <<  "|     +2     |" << std::endl;
                    }
                    else if (tempVal == 11) {
                        std::cout <<  "|     +4     |" << std::endl;
                    }
                    else if (tempVal == 12) {
                        std::cout <<  "|Color change|" << std::endl;
                    }        
                    else {
                        std::cout <<  "|     " << tempVal << "      |" << std::endl;
                    }
                } 
            }
        std::cout << "--------------" << std::endl;;   
    } 
    std::cout << "\x1b[0m@@@";
}

void Deck::PlaceCard(int a, int b) {
        node *tempVal = new node;
        tempVal->cardNumber = a;
        tempVal->cardColor = b;
        tempVal->next = NULL;

        if(head == NULL) {
            head = tempVal;
            tail = tempVal;
        }
        else {
            tail->next = tempVal;
            tail = tail->next;
        }
    }
