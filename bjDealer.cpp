
#include "bjDealer.h"

void bjDealer::givePlayercard(std::shared_ptr<bjCards> card, bool checkMain) {

    main.giveCard(card);
}


int bjDealer::getValue(bool checkMain) {
    return main.getPlayerTotalvalue();
}


void bjDealer::resetHand() {
    main.resetBetamount();
    main.clear();
}

void bjDealer::showFirstCard() {
    main.showfirstCard();
}

void bjDealer::showAllCards(bool checkMain) {

    main.showcards();
}

void bjDealer::printValue() {
    main.showValue();
}



