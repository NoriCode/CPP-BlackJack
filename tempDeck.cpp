//
// Created by nori on 29.06.20.
//

#include "tempDeck.h"
#include <algorithm>
#include <random>
#include "bjCards.h"

void tempDeck::addCardtoDeck(bjCards *card) {
    deck.push_back(card);
}


std::vector<bjCards *> tempDeck::getDeck() {
    return deck;
}

bjCards *tempDeck::playFirstCardFromStack() {
    bjCards *output = deck.front();
    collectPlayedCards(output);
    deck.erase(deck.begin());
    return output;
}


void tempDeck::reduceCardCounter() {
    cardCounter--;
}

void tempDeck::collectPlayedCards(bjCards *card) {
    playedCards.push_back(card);
    deck.erase(deck.begin());
    reduceCardCounter();
}

void tempDeck::generatePlayCardsAndAddtoDeck(int maxDecks) {
    for (int i = 0; i < maxDecks; ++i) {
        for (int j = 0; j < 13; j++) {
            int value = j + 2;
            if (value > 10) {
                value = 10;
                if (j == 12) {
                    value = 11;
                }
            }
            addCardtoDeck(new bjCards("hearts", getNumberX(j), value));
            addCardtoDeck(new bjCards("bells", getNumberX(j), value));
            addCardtoDeck(new bjCards("leaves", getNumberX(j), value));
            addCardtoDeck(new bjCards("acorns", getNumberX(j), value));
        }
        deckShuffel();
    }
    deckShuffel();
    setCardCounter(deck.size());
}


void tempDeck::resetPlayDeck() {
    for (bjCards *card : playedCards) {
        addCardtoDeck(card);
    }
    playedCards.clear();
    setCardCounter(deck.size());
}

void tempDeck::deckShuffel() {
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

void tempDeck::setCardCounter(int i) {
    cardCounter = i;
}

std::string tempDeck::getNumberX(int x) {
    return numberList[x];
}


int tempDeck::getTotalValue() {
    int value = 0;
    for (bjCards *card : deck) {
        value += card->getValue();
    }
    return value;
}

bool tempDeck::reShuffelWasNeeded() {
    if (cardCounter <= 75) {
        deckShuffel();
        return true;
    }
    return false;
}
