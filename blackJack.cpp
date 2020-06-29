//
// Created by philip_nori on 29.06.20.
//

#include "blackJack.h"

void blackJack::game() {
    menu();
    if (gs == NEWGAME) {
        newGame();
        gs = static_cast<gameState>(3);
    }

    //bet
    p->bet(bjR->getMinBet(), bjR->getMaxBet());

    //spieler und dealer bekommen Karte P,D,P,D
    drawInitialCards();
    //karten werden gedreht
    showCards();
    //spieler: hit stand loop unterbrochen durch 21 oder höher
    {
        bool checkMain = true;
        while (gs == PLAYING) {
            playerRoundOptions();
            if (po == SPLIT) {
                p->splitCards();
            } else if (po = HIT) {
                draw(checkMain);
            } else if (po == STAND) {
                if (p->playerHasSplit() && checkMain) {
                    checkMain = false;
                    ps = static_cast<playerStatus>(3);
                } else {
                    gs = static_cast<gameState>(4);
                }
            }
            checkEarlyVictoryCondidtion(checkMain);
        }
    }

    //dealer phase
    while (d->getValue(true) < bjR->getDealerMaxPoints()) {
        if (p->playerHasSplit()) {
            draw(true);
        }
    }

    //cashout
    if (ps == DNF) {
        bool exit = false;
        bool checkMain = true;
        while (!exit) {
            if (p->getValue(checkMain) < d->getValue(true)) {
                p->collectBet(checkMain);
            } else if (p->getValue(checkMain) == d->getValue(true)) {
                p->giveBetBack(checkMain);
            } else if (p->getValue(checkMain) > d->getValue(true)) {
                p->payWinSum(checkMain);
            }
            if (p->playerHasSplit()) {
                checkMain = false;
            } else {
                exit = true;
            }
        }
        p->resetHand();
        d->resetHand();
    }
    playAnotherRound();

}

void blackJack::drawInitialCards() {
    for (int i = 0; i < 2; i++) {
        p->givePlayercard(cD.playFirstCardFromStack(), true);
        d->givePlayercard(cD.playFirstCardFromStack(), true);
    }

}

void blackJack::kickPlayerIfBroke() {
    p->isBroke(bjR->getMinBet());
    mm = static_cast<mainMenu>(3);
    printf("Bouncer: You dont own enough Chips to play. You have to leave the Casino\n");
    exitGame();
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
    if (mm == EXIT) {
        return true;
    }
    return false;
}

bool blackJack::leaveTable() {
    if (gs == LEAVE) {
        return true;
    }

    return false;
}

void blackJack::newGame() {
    cD.generatePlayCardsAndAddtoDeck(bjR->getNumberOfDecks());

    cD.reshuffelIfNeeded();
}

void blackJack::showCards() {
    printf("The open Card of the dealer is: ");
    d->showFirstCard();

    printf("You have this Cards");
    p->showAllCards(true);

}

void blackJack::playAnotherRound() {
    int in;
    printf("Do you want to play a new round?\n");

    printf("1 - yes\n");
    printf("Enter any Key to leave the table.");
    printf("Your choice: ");
    std::cin >> in;
    printf("\n");

    if (in != 1) {
        in = 2;
    }
    gs = static_cast<gameState>(in);
}

void blackJack::draw(bool checkMain) {

    if (po == HIT) {
        p->givePlayercard(cD.playFirstCardFromStack(), checkMain);
    } else if (po == STAND) {
        d->givePlayercard(cD.playFirstCardFromStack(), true);
    }
}

void blackJack::playerRoundOptions() {
    bool invalid = true;
    int in;

    while (invalid) {

        printf("Your options are\n");

        if (p->canPlayerSplit()) {
            printf("0 -> split\n");
        }

        printf("1 -> hit\n");
        printf("2 -> stand\n");
        printf("Your choice: ");
        std::cin >> in;

        if ((in == 0 && !p->canPlayerSplit()) || in < 0 || in > 2) {
            printf("Invalid Choice. Please enter again\n");
        } else {
            invalid = false;
        }
    }
    printf("\n");

    po = static_cast<playerOption>(in);

}

void blackJack::checkEarlyVictoryCondidtion(bool checkMain) {
    if (p->getValue(checkMain) == 21) {
        ps = static_cast<playerStatus>(1);
    } else if (p->getValue(checkMain) > 21) {
        ps = static_cast<playerStatus>(2);
    }
}

