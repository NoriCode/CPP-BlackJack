//
// Created by philip_nori on 29.06.20.
//

#include "blackJack.h"

void blackJack::game() {
    if(gs==NEWGAME){
        newGame();
        gs = static_cast<gameState>(1);
    }

    //bet
    p->bet(bjR->getMinBet(),bjR->getMaxBet());

    //spieler und dealer bekommen Karte P,D,P,D
    //karten werden gedreht
    //spieler: hit stand loop unterbrochen durch 21 oder höher
    //dealer phase
    //cashout

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
    cD.generatePlayCardsAndAddtoDeck(bjR->getNumberOfDecks());

    for (int i = 0; i < 2; i++) {
        p->giveMainCard(cD.playFirstCardFromStack());

        d->giveMainCard(cD.playFirstCardFromStack());
    }


    printf("The open Card of the dealer is: ");
    d->showOPenCard();

    p->showCards("You");
    p->bet(bjR->getMinBet(), bjR->getMaxBet());
}
