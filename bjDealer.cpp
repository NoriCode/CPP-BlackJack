//
// Created by nori on 30.06.20.
//

#include "bjDealer.h"

void bjDealer::givePlayercard(bjCards *card, bool checkMain) {

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


