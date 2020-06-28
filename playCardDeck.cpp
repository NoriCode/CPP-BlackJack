#include "playCardDeck.h"
#include <algorithm>
#include <random>
#include "bjCards.h"

void playCardDeck::generatePlayDeck(int maxDecks) {
    for (int i = 0; i < maxDecks; ++i) {
        for (int j = 0; j < 13; j++) {
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
    setCardCounter(_deck.size());
}



void playCardDeck::resetPlayDeck() {
    for (bjCards *card : _playedCards) {
        addPlayDeck(card);
    }
    _playedCards.clear();
    setCardCounter(_deck.size());
}

void playCardDeck::deckShuffel() {
    std::shuffle(_deck.begin(), _deck.end(), std::mt19937(std::random_device()()));
}

void playCardDeck::setCardCounter(int i) {
    _cardCounter = i;
}

std::string playCardDeck::getNumberX(int x) {
    return numberList[x];
}
