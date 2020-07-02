
#include "bjDealer.h"

void bjDealer::givePlayercard(std::shared_ptr<bjCards> card) {

    main.giveCard(card);
}


int bjDealer::getValue() {
   // return main.getPlayerTotalvalue();
    return 0;
}


void bjDealer::resetHand() {
    main = new bjHand();
}

void bjDealer::showAllCards(bool checkMain) {

    main.showcards();
}

void bjDealer::printValue() {
//    main.showValue();
}



