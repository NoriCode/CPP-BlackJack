#ifndef CCPP_EXAM_PLAYCARDDECK_H
#define CCPP_EXAM_PLAYCARDDECK_H

#include <vector>
#include <algorithm>
#include "cards.h"
#include "bjCards.h"
#include "deck.h"

class playCardDeck : public deck {
protected:
    std::string numberList[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};



    void setCardCounter(int i);

    std::string getNumberX(int x);

public:
    void generatePlayDeck(int maxDecks);

    void resetPlayDeck();


    void deckShuffel();
};


#endif //CCPP_EXAM_PLAYCARDDECK_H
