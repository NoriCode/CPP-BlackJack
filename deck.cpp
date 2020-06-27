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

bjCards* deck::getCardX(int x) {
    int count;
    for (bjCards *card : _deck) {
        count++;
        if (count == x){
            return card;
        }
    }
    return 0;
}
