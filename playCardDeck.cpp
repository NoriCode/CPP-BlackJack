#include "playCardDeck.h"
#include <algorithm>
#include "bjCards.h"

void playCardDeck::generatePlayDeck(int count) {
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

    std::random_shuffle(_playDeck->begin(), _playDeck->end());

    for (cards *cards : *_playDeck) {
        cards->whoAmI();
    }
}