#include "gameData.h"

void Card::DisplayCard() {
    std::string display = "";
    switch(color) {
        case 'R':
            display.append(RED);
            break;
        case 'B':
            display.append(BLUE);
            break;
        case 'G':
            display.append(GREEN);
            break;
        case 'Y':
            display.append(YELLOW);
            break;
        case 'W':
            display.append(DEFAULT);
    }

    std::cout << display + "--------------" << std::endl;
    for (int j = 0; j < 8; j++) {
        if (j != 4)
            std::cout << "|            |" << std::endl;
        else {      
            switch(number) {
                case PLUS_TWO:
                    std::cout <<  "|     +2     |" << std::endl;
                    break;
                case PLUS_FOUR:
                    std::cout <<  "|     +4     |" << std::endl;
                    break;
                case COLOR_CHANGE:
                    std::cout <<  "|Color change|" << std::endl;
                    break;
                default:
                    std::cout <<  "|     " << number << "      |" << std::endl;
                    break;
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

    //Number is +2 card
    if (number == -5 && color - 48 == 2) {
        number = PLUS_TWO;
        color = 'W';
    }
    //Number is a +4 card
    else if (number == -5 && color -48 == 4) {
        number = PLUS_FOUR;
        color = 'W';
    }
    //Number is a color change
    else if (number == 19 && color == 'C') {
        number = COLOR_CHANGE;
        color = 'W';
    }

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

int Hand::GetSize() {
    return cardHand.size();
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

int Player::GetNumCards() {
    return hand.GetSize();
}
