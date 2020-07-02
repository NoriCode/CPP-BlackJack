
#include "bjDeck.h"
#include <algorithm>
#include <random>
#include "bjCards.h"

void bjDeck::addCardtoDeck(const std::shared_ptr<bjCards>& card) {
    deck.push_back(card);
}


std::vector<std::shared_ptr<bjCards>> bjDeck::getDeck() {
    return deck;
}

std::shared_ptr<bjCards> bjDeck::playFirstCardFromStack() {
    std::shared_ptr<bjCards> output = deck.front();
    collectPlayedCards(output);
    deck.erase(deck.begin());
    return output;
}


void bjDeck::reduceCardCounter() {
    cardCounter--;
}

void bjDeck::collectPlayedCards(const std::shared_ptr<bjCards>& card) {

    playedCards.push_back(card);
    //deck.erase(deck.at(0)));
    deck.empty();
    reduceCardCounter();
}

void bjDeck::generatePlayCardsAndAddtoDeck(int maxDecks) {
    for (int i = 0; i < maxDecks; ++i) {
        for (int j = 0; j < 13; j++) {
            int value = j + 2;
            if (value > 10) {
                value = 10;
                if (j == 12) {
                    value = 11;
                }
            }
            addCardtoDeck(static_cast<std::shared_ptr<bjCards>>(new bjCards("hearts", getNumberX(j), value)));
            addCardtoDeck(static_cast<std::shared_ptr<bjCards>>(new bjCards("bells", getNumberX(j), value)));
            addCardtoDeck(static_cast<std::shared_ptr<bjCards>>(new bjCards("leaves", getNumberX(j), value)));
            addCardtoDeck(static_cast<std::shared_ptr<bjCards>>(new bjCards("acorns", getNumberX(j), value)));
        }
        deckShuffel();
    }
    deckShuffel();
    setCardCounter(deck.size());
}

void bjDeck::deckShuffel() {
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

void bjDeck::setCardCounter(int i) {
    cardCounter = i;
}

std::string bjDeck::getNumberX(int x) {
    return numberList[x];
}


int bjDeck::getTotalValue() {
    int value = 0;
    for (const std::shared_ptr<bjCards>& card : deck) {
        value += card->getValue();
    }
    return value;
}

void bjDeck::reshuffelIfNeeded(int trigger) {
    if (cardCounter <= trigger) {
        deckShuffel();
    }
}
