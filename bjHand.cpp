//
// Created by philip_nori on 29.06.20.
//

#include "bjHand.h"

void bjHand::split() {
}

bool bjHand::canSplit() {
    return splitAllowed;
}

int bjHand::getBetAmount() {
    return betAmount;
}

int bjHand::payout(int bet) {
    return (int) bet * 1.5;
}

void bjHand::resetBetamount() {
    betAmount = 0;
}

bjCards *bjHand::removeCard() {

    return mainDeck.getDeck().front();
}

void bjHand::giveCard() {
    mainDeck.a
}
