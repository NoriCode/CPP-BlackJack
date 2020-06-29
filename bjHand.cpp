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

int bjHand::payout() {
    return (int) betAmount * 1.5;
}

void bjHand::resetBetamount() {
    betAmount = 0;
}

bjCards *bjHand::removeFirstCard() {
    return deck.getDeck().front();
}

void bjHand::giveCard(bjCards *card) {
    amIReal = true;
    deck.addCardtoDeck(card);
}

void bjHand::showcards() {
    for(bjCards *card: deck.getDeck()){
        card->whoAmI();
    }
}

void bjHand::bet(int playerBet) {
    betAmount = playerBet;
}

int bjHand::givePlayerBetBack() {
    return betAmount;
}

void bjHand::clear() {
    deck.getDeck().empty();
    amIReal = false;
}

bool bjHand::exist() {
    return amIReal;
}
