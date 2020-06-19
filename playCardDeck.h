#ifndef CCPP_EXAM_PLAYCARDDECK_H
#define CCPP_EXAM_PLAYCARDDECK_H

#include <vector>
#include "cards.h"
#include "bjCards.h"

class playCardDeck {
protected:
    std::string numberList[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};
    std::vector<bjCards *> *_playDeck;
    int _cardCounter;
public:
    void generatePlayDeck(int count);

    void addPlayDeck(bjCards *card) {
        _playDeck->push_back(card);
    }

    void setCardCounter(int i) {
        _cardCounter = i;
    }

    int getCardCounter(int i) {
        return _cardCounter;
    }

    std::string getNumberX(int x) {
        return numberList[x];
    }
};


#endif //CCPP_EXAM_PLAYCARDDECK_H
