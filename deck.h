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
    std::vector<bjCards *> deck;
    int cardCounter;
    std::vector<bjCards *> playedCards;


    void reduceCardCounter();

public:

    void addPlayDeck(bjCards *card);

    int getCardCounter();

    bjCards *getCardX(int x);

    std::vector<bjCards *> getDeck();

    bjCards *giveOutCard();

    void playedCardsCollector(bjCards *card);
};


#endif //CCPP_EXAM_DECK_H
