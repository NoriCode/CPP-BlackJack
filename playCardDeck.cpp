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
                if (j == 12) {
                    value = 11;
                }
            }
            addPlayDeck(new bjCards("hearts", getNumberX(j), value));
            addPlayDeck(new bjCards("bells", getNumberX(j), value));
            addPlayDeck(new bjCards("leaves", getNumberX(j), value));
            addPlayDeck(new bjCards("acorns", getNumberX(j), value));
        }
    }
    setCardCounter(deck.size());
}


void playCardDeck::resetPlayDeck() {
    for (bjCards *card : playedCards) {
        addPlayDeck(card);
    }
    playedCards.clear();
    setCardCounter(deck.size());
}

void playCardDeck::deckShuffel() {
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

void playCardDeck::setCardCounter(int i) {
    cardCounter = i;
}

std::string playCardDeck::getNumberX(int x) {
    return numberList[x];
}
