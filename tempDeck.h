//
// Created by nori on 29.06.20.
//

#ifndef CCPP_EXAM_TEMPDECK_H
#define CCPP_EXAM_TEMPDECK_H

#include <vector>
#include <algorithm>
#include "replaced/cards.h"
#include "bjCards.h"

class tempDeck {
private:
    std::vector<bjCards *> deck;
    int cardCounter;
    std::vector<bjCards *> playedCards;

    void reduceCardCounter();

    std::string numberList[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};

    void setCardCounter(int i);

    std::string getNumberX(int x);


    void deckShuffel();


    void resetPlayDeck();



public:

    void addCardtoDeck(bjCards *card);

    std::vector<bjCards *> getDeck();

    bjCards *playFirstCardFromStack();

    void collectPlayedCards(bjCards *card);

    void generatePlayCardsAndAddtoDeck(int maxDecks);

    int getTotalValue();

    void reshuffelIfNeeded(int trigger);


};


#endif //CCPP_EXAM_TEMPDECK_H
