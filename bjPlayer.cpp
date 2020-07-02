
#include "bjPlayer.h"
#include <cstdio>
#include <regex>
#include <utility>

void bjPlayer::givePlayercard(std::shared_ptr<bjCards> card) {

    playerCards.giveCard(std::move(card));
}

int bjPlayer::getValue(bool player) {

    return playerCards.getPlayerTotalvalue(player);
}


void bjPlayer::resetHand() {
    playerCards = new bjHand();
}

bool bjPlayer::isBroke(int min) const {
    return chips < min;
}

void bjPlayer::payWinSum() {

    chips += playerCards.payout();
}

void bjPlayer::collectBet() {

    playerCards.resetBetamount();

}

void bjPlayer::giveBetBack() {

    chips += playerCards.givePlayerBetBack();

}

void bjPlayer::showAllCards() {

    playerCards.showcards();
}

void bjPlayer::printValue(bool player) {
    playerCards.showValue(player);
}

void bjPlayer::bet(int bet) {
    chips -= bet;
    playerCards.bet(bet);
}

int bjPlayer::getChips() const {
    return chips;
}


void bjPlayer::showFirstCard() {
    playerCards.showfirstCard();
}


