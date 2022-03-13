#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define DEFAULT "\x1b[0m"
#define CLEAR "\033[2J\033[1;1H"

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
        void assignColor(char newColor) {
            color = newColor;
        }
        void assignNumber(int newNumber) {
            number = newNumber;
        }
        char getColor() {
            return color;
        }
        int getNumber() {
            return number;
        }
};


class Hand {
        std::vector<Card*> cardHand;
    public:
        void Init() {
            cardHand.resize(7);
            for (int i = 0; i < 7; i++) {
                cardHand[i] = new Card();
            }
        }
        void Display();
        Card* Find(std::string cardVal);
        void Delete(Card* card);
};

class Player {
        // Player score, highest no of cards, stats
        Hand hand;
        int highestNumCards;
    public:
        void InitHand() { 
            hand.Init();
            highestNumCards = 7;
        }

        Card* FindCard(std::string cardVal);
        void DeleteCard(Card* card);
        void DisplayHand();
};



#endif