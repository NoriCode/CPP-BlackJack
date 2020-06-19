#include "playCardDeck.h"
#include <stdio.h>

int playCardDeck::doStuff() {
    return 1;
}

void playCardDeck::generateCards() {
    for (int i = 0; i < 52; ++i) {
        printf("%d\n", i);
    }
}