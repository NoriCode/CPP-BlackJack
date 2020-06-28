//
// Created by philip_nori on 27.06.20.
//

#include "deck.h"

int deck::getCardCounter() {

    return _cardCounter;
}

void deck::addPlayDeck(bjCards *card) {
    _deck.push_back(card);
}

bjCards *deck::getCardX(int x) {
    int count = 0;
    for (bjCards *card : _deck) {
        count++;
        if (count == x) {
            return card;
        }
    }
    return 0;
}

std::vector<bjCards *> deck::getDeck() {
    return _deck;
}

bjCards *deck::giveOutCard() {
    bjCards *output = _deck.front();
    playedCardsCollector(output);
    return output;
}


void deck::reduceCardCounter() {
    _cardCounter--;
}

void deck::playedCardsCollector(bjCards *card) {
    _playedCards.push_back(card);
    _deck.erase(_deck.begin());
    reduceCardCounter();
}
