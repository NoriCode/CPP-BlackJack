
#ifndef CCPP_EXAM_BJDECK_H
#define CCPP_EXAM_BJDECK_H

#include <vector>
#include <algorithm>
#include "bjCards.h"
#include <cstdio>
#include <memory>

class bjDeck {
private:
    std::vector<std::shared_ptr<bjCards>> deck;
    int cardCounter;
    std::vector<std::shared_ptr<bjCards>> playedCards;

    void reduceCardCounter();

    std::string numberList[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};

    void setCardCounter(int i);

    std::string getNumberX(int x);


    void deckShuffel();


public:

    void addCardtoDeck(const std::shared_ptr<bjCards>& card);

    std::vector<std::shared_ptr<bjCards>> getDeck();

    std::shared_ptr<bjCards> playFirstCardFromStack();

    void collectPlayedCards(bjCards *card);

    void generatePlayCardsAndAddtoDeck(int maxDecks);

    int getTotalValue();

    void reshuffelIfNeeded(int trigger);


    void collectPlayedCards(const std::shared_ptr<bjCards>& card);
};


#endif //CCPP_EXAM_BJDECK_H
