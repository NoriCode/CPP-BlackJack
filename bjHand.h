//
// Created by philip_nori on 29.06.20.
//

#ifndef CCPP_EXAM_BJHAND_H
#define CCPP_EXAM_BJHAND_H
#include "bjCards.h"
#include "playerdeck.h"

class bjHand {
private:
    int betAmount;
    playerdeck mainDeck;
    bool splitAllowed;

public:

    void split();

    void repayBet();

    void resetDeck();

    void resetBetamount();

    void giveCard();

    bool canSplit();

    int getTotalvalue();


    int getBetAmount();

    int payout(int bet);

    bjCards *removeCard();
};


#endif //CCPP_EXAM_BJHAND_H
