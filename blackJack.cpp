//
// Created by philip_nori on 29.06.20.
//

#include "blackJack.h"

void blackJack::game() {

}

void blackJack::draw() {

}

void blackJack::kickPlayer() {

}

void blackJack::menu() {
    int in;
    printf("Welcome to Blackjack\n");
    printf("Your options are:\n");
    printf("1 - Play\n");
    printf("2 - Rules\n");
    printf("3 - Exit\n");
    printf("Your choice: ");
    std::cin >> in;
    printf("\n");

    mm = static_cast<mainMenu>(in);
}

bool blackJack::exitGame() {
    if (mm == EXIT){
        return true;
    }
    return false;
}

bool blackJack::leaveTable() {

    if (po == LEAVE){
        return true;
    }
    return false;
}

void blackJack::newGame() {
    pCD.generatePlayDeck(bjR->getNumberOfDecks());
    pCD.deckShuffel();
    for (int i = 0; i < 2; i++) {
        p->giveMainCard(pCD.giveOutCard());

        d->giveMainCard(pCD.giveOutCard());
    }


    if (pCD.getCardCounter() <= bjR->getReshuffelTrigger()) {
        pCD.deckShuffel();
    }
    printf("The open Card of the dealer is: ");
    d->showOPenCard();

    p->showCards("You");
    p->bet(bjR->getMinBet(), bjR->getMaxBet());

}
