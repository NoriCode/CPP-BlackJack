
#include "bjHand.h"

#include <utility>

void bjHand::split() {
}

bool bjHand::canSplit() {
    return deck.getDeck().at(0)->getValue() == deck.getDeck().at(1)->getValue();
}

int bjHand::getBetAmount() const {
    return betAmount;
}

int bjHand::payout() const {
    return (int) betAmount * 1.5;
}

void bjHand::resetBetamount() {
    betAmount = 0;
}

std::shared_ptr<bjCards> bjHand::removeFirstCard() {
    return deck.getDeck().front();
}

void bjHand::giveCard(std::shared_ptr<bjCards> card) {
    amIReal = true;
    deck.addCardtoDeck(std::move(card));
}

void bjHand::showcards() {
    for (const std::shared_ptr<bjCards>& card: deck.getDeck()) {
        card->whoAmI();
    }
}

void bjHand::bet(int playerBet) {
    betAmount = playerBet;
}

int bjHand::givePlayerBetBack() const {
    return betAmount;
}

void bjHand::clear() {

    for (std::shared_ptr<bjCards> card: deck.getDeck()) {
        card.reset();
    }

    amIReal = false;
}

bool bjHand::exist() const {
    return amIReal;
}

void bjHand::showfirstCard() {
    deck.getDeck().front()->whoAmI();
}


int bjHand::getPlayerTotalvalue() {
    for (const std::shared_ptr<bjCards>& card: deck.getDeck()) {
        if (card->getnumber() == "A") {
            if (deck.getTotalValue() > 21) {
                card->setValue(1);
            }
        }
    }
    return deck.getTotalValue();
}

bjHand::bjHand(bjHand *pHand) {

}

bjHand::bjHand() = default;

void bjHand::showValue() {
    printf("The cards have a value of: %i\n", getPlayerTotalvalue());
}

int bjHand::getDealerTotalValue() {

    return deck.getTotalValue();
}
