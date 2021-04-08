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
        void cardGUI(int number, char color);
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

class Deck: public Cards {
    node *head, *tail;
    public:
        Deck() {
            head = NULL;
            tail = NULL;
        }
        void PlaceCard(int a, int b);
        void DisplayTopCard() {
            if (tail == NULL) {
                std::cout << "EMPTY";
            }
            else {
                cardGUI(tail->cardNumber,tail->cardColor);
            }
        }
        void Display();
};

//------------- FUNCTIONS ---------------

Cards::Cards() {
    srand (time(NULL));
    for (int i = 0; i  < 7; i++) {
        cardHand.push_back(rand() % 12 + 1);   
        int tempVal = rand() % 4;
        if (tempVal == 0) {
            cardColor.push_back('R');
        }
        else if (tempVal == 1) {
            cardColor.push_back('B');
        }
        else if (tempVal == 2) {
            cardColor.push_back('G');
        }
        else {
            cardColor.push_back('Y');
        }
    }
}

void Cards::cardGUI(int number, char color) {
    std::string tempVal;
    if (color == 'R') {
        tempVal.append("\x1b[31m");
    }
    else if (color == 'B') {
        tempVal.append("\x1b[34m");
    }
    else if (color == 'G') {
        tempVal.append("\x1b[32m");
    }
    else if (color == 'Y') {
        tempVal.append("\x1b[33m");
    }
    if (number >= 10) {
        tempVal.append("\x1b[0m");
    }
    std::cout << tempVal + "--------------" << std::endl;
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
        std::cout << "--------------" << std::endl;   
     
    std::cout << "\x1b[0m";
}
Player::Player() {
    
}
void Player::DisplayCards() {
    for (int i = 0; i < 7; i++) {
        int tempVal = returnCard(i);
        cardGUI(returnCard(i), returnColor(i));
    } 
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

void Deck::Display() {
    node *tempVal = new node;
    tempVal = head;
    while(tempVal!=NULL) {
      std::cout<<tempVal->cardNumber;
      tempVal=tempVal->next;
    }

}