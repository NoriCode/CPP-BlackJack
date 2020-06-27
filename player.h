#ifndef CCPP_EXAM_PLAYER_H
#define CCPP_EXAM_PLAYER_H

#include "cards.h"
#include "bjCards.h"
#include <vector>
#include "playerdeck.h"
#include "bjRuleController.h"


class player {
private:
    playerdeck left;
    playerdeck right;
    int chips;
    bool splitAllowed;
    bool hasSplit;

    int rightBet(int bet, int min, int max);
    int oneEleven();


public:
    explicit player(int c = 0) : chips(c) {}

    bool canSplit();

    void split();

    void bet(int min, int max);

    void giveLeftCard(bjCards *card);

    void giveRightCard(bjCards *card);

    int rightValue();

    int leftValue();

    int getChips();

    bool hasSplited();

    void blackjack();

};


#endif //CCPP_EXAM_PLAYER_H
