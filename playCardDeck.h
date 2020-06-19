#ifndef CCPP_EXAM_PLAYCARDDECK_H
#define CCPP_EXAM_PLAYCARDDECK_H

#include <vector>
#include "cards.h"

class playCardDeck{
protected:
    std::vector<cards *> deck;
    int cardCounter;
public:
    static void generateCards();
    int doStuff();
    void setCardCounter(int i) {
        cardCounter = i;
    }
    int getCardCounter(int i) {
        return cardCounter;
    }
};


#endif //CCPP_EXAM_PLAYCARDDECK_H
