//
// Created by philip_nori on 28.06.20.
//

#include "player.h"

int player::mainValue() {
    return _mainDeck.getTotalValue();
}

void player::giveMainCard(bjCards *card) {
    if (card->getnumber() == ("A")) {
        card->setValue(oneEleven());
    }

    _mainDeck.addPlayDeck(card);
    printf("%i", mainValue());
    //todo karten genau anzeigen nicht nur wert
}

int player::oneEleven() {
    int in;
    while (in != 1 && in != 11) {
        printf("You have drawn an Ace. You can decide if it has the value 1 or 11\n");
        printf("Which Value has your Ace: ");
        std::cin >> in;
    }
    return in;
}

void player::showCards(std::string name) {
    printf("The Player %s has this Cards: \n", name.c_str());
    for (bjCards *cards : _mainDeck.getDeck()) {
        cards->whoAmI();
    }

}

