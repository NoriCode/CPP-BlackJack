//Topic 14:  Object Orientation: Interface vs. Implementation *

#include "bjHand.h"


unsigned int bjHand::payout() const {
    //Topic 8: Daten Bitoperation
    return betAmount << 1u;
}

void bjHand::resetBetamount() {
    betAmount = 0;
}

void bjHand::giveCard(const std::shared_ptr<bjCards> &card) {
    deck.addCardtoDeck(card);
}

void bjHand::showcards() {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    for (const std::shared_ptr<bjCards> &card: deck.getDeck()) {
        card->whoAmI();
    }
}

void bjHand::bet(unsigned int playerBet) {
    betAmount = playerBet;
}

unsigned int bjHand::givePlayerBetBack() const {
    return betAmount;
}

void bjHand::showfirstCard() {
    deck.getDeck().front()->whoAmI();
}


int bjHand::getPlayerTotalvalue(bool player) {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (player) {
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        //Topic 26: Häufige fehlerquellen -> Index out of Bounds wird durch for each abgefangen
        for (const std::shared_ptr<bjCards> &card: deck.getDeck()) {
            //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
            if (card->getNumber() == "A") {
                //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
                if (deck.getTotalValue() > 21) {
                    card->setValue(1);
                }
            }
        }
    }
    return deck.getTotalValue();
}


bjHand::bjHand() = default;

void bjHand::showValue(bool player) {
    printf("The cards have a value of: %i\n", getPlayerTotalvalue(player));
}