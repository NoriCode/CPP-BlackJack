//
// Created by philip_nori on 28.06.20.
//

#include "player.h"

int player::mainValue() {
    return _mainDeck.getTotalValue();
}

void player::giveMainCard(bjCards *card) {
    _mainDeck.addPlayDeck(card);
    printf("You drawn this card");
    card->whoAmI();
    //todo karten genau anzeigen nicht nur wert
}



void player::showCards(std::string name) {
    printf("The Player %s has this Cards: \n", name.c_str());
    for (bjCards *cards : _mainDeck.getDeck()) {
        cards->whoAmI();
    }

}

void player::resetMainDeck() {
    _mainDeck.getDeck().clear();
}

