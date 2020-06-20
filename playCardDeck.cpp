#include "playCardDeck.h"
#include <algorithm>
#include "bjCards.h"

void playCardDeck::generatePlayDeck() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 13; ++j) {
            int value = j + 2;
            if (value > 10) {
                value = 10;
            }
            addPlayDeck(new bjCards("hearts", getNumberX(j), value));
            addPlayDeck(new bjCards("bells", getNumberX(j), value));
            addPlayDeck(new bjCards("leaves", getNumberX(j), value));
            addPlayDeck(new bjCards("acorns", getNumberX(j), value));
        }
    }
    setCardCounter(_playDeck.size());
}

void playCardDeck::addPlayDeck(bjCards *card) {
    _playDeck.push_back(card);
}

void playCardDeck::playedCardsCollector(bjCards *card) {
    _playedCards.push_back(card);
    _playDeck.erase(_playDeck.begin());
    reduceCardCounter();
}

void playCardDeck::resetPlayDeck() {
    for (bjCards *card : _playedCards) {
        addPlayDeck(card);
    }
    _playedCards.clear();
    setCardCounter(_playDeck.size());
}

void playCardDeck::deckShuffel() {
    std::random_shuffle(_playDeck.begin(), _playDeck.end());
}

void playCardDeck::setCardCounter(int i) {
    _cardCounter = i;
}

int playCardDeck::getCardCounter(int i) {
    return _cardCounter;
}

void playCardDeck::reduceCardCounter() {
    _cardCounter--;
}

std::string playCardDeck::getNumberX(int x) {
    return numberList[x];
}