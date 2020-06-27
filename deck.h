//
// Created by philip_nori on 27.06.20.
//

#ifndef CCPP_EXAM_DECK_H
#define CCPP_EXAM_DECK_H
#include <vector>
#include <algorithm>
#include "cards.h"
#include "bjCards.h"


class deck {
protected:
    std::vector<bjCards *> _deck;
    int _cardCounter;
public:

    void addPlayDeck(bjCards *card);
    int getCardCounter();
    bjCards* getCardX(int x);
};


#endif //CCPP_EXAM_DECK_H
