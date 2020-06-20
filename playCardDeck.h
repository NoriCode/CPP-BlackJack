#ifndef CCPP_EXAM_PLAYCARDDECK_H
#define CCPP_EXAM_PLAYCARDDECK_H

#include <vector>
#include <algorithm>
#include "cards.h"
#include "bjCards.h"

class playCardDeck {
protected:
    std::string numberList[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};
    std::vector<bjCards *> _playDeck;
    std::vector<bjCards *> _playedCards;
    int _cardCounter;

    void setCardCounter(int i);

    void reduceCardCounter();

    std::string getNumberX(int x);

    void addPlayDeck(bjCards *card);

public:
    void generatePlayDeck();

    void resetPlayDeck();

    void playedCardsCollector(bjCards *card);

    void deckShuffel();

    int getCardCounter(int i);
};


#endif //CCPP_EXAM_PLAYCARDDECK_H
