//Topic 13:  Object Orientation: Inheritance
#include "bjPlayer.h"

void bjPlayer::givePlayercard(const std::shared_ptr<bjCards> &card) {

    playerCards.giveCard(card);
}

int bjPlayer::getValue(bool player) {

    return playerCards.getPlayerTotalvalue(player);
}


void bjPlayer::resetHand() {
    playerCards = bjHand();
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

bjPlayer::bjPlayer() = default;


