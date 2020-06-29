//
// Created by philip_nori on 27.06.20.
//

#include "playerdeck.h"

int playerdeck::getTotalValue() {
    int value = 0;
    for (bjCards *card : deck) {
        value += card->getValue();
    }
    return value;
}


