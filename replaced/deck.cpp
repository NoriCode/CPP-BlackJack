//
// Created by philip_nori on 27.06.20.
//

#include "deck.h"

int deck::getCardCounter() {

    return cardCounter;
}

void deck::addPlayDeck(bjCards *card) {
    deck.push_back(card);
}

bjCards *deck::getCardX(int x) {
    int count = 0;
    for (bjCards *card : deck) {
        count++;
        if (count == x) {
            return card;
        }
    }
    return 0;
}

std::vector<bjCards *> deck::getDeck() {
    return deck;
}

bjCards *deck::giveOutCard() {
    bjCards *output = deck.front();
    playedCardsCollector(output);
    return output;
}


void deck::reduceCardCounter() {
    cardCounter--;
}

void deck::playedCardsCollector(bjCards *card) {
    playedCards.push_back(card);
    deck.erase(deck.begin());
    reduceCardCounter();
}
