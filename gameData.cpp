#include "gameData.h"

void Card::DisplayCard() {
    std::string display = "";
    if (color == 'R') {
        display.append(RED);
    }
    else if (color == 'B') {
            display.append(BLUE);
    }
    else if (color == 'G') {
        display.append(GREEN);
    }
    else if (color == 'Y') {
        display.append(YELLOW);
    }

    if (number >= 10) {
        display.append(DEFAULT);
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
    std::cout << DEFAULT;
}

void Hand::Display() {
    for (int i = 0; i < cardHand.size(); i++) {
        cardHand[i]->DisplayCard();
    }
}

Card* Hand::Find(std::string cardVal) {
    int number = (int)cardVal[0] - 48;
    char color = cardVal[1];
    
    //Iterate and return card in hand
    for (int i = 0; i < cardHand.size(); i++) {
        if (cardHand[i]->getColor() == color && cardHand[i]->getNumber() == number) {
            return cardHand[i];
        }

    }

    //Card does not exist
    return NULL;
}

void Hand::Delete(Card* card) {
    int number = card->getNumber();
    int color = card->getColor();

    //Iterate and delete card in hand
    for (int i = 0; i < cardHand.size(); i++) {
        if (cardHand[i]->getColor() == color && cardHand[i]->getNumber() == number)  {  
            cardHand.erase(cardHand.begin() + i);
            break;
        }
    }
}

void Hand::Get() {
    cardHand.push_back(new Card());
}

void Player::DisplayHand() {
    hand.Display();
}

Card* Player::FindCard(std::string cardVal) {
    return hand.Find(cardVal);
}

void Player::DeleteCard(Card* card) {
    hand.Delete(card);
} 

void Player::GetNewCard() {
    hand.Get();
}
