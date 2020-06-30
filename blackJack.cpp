

#include "blackJack.h"
#include "bjRuleController.h"

void blackJack::game() {
    while (mm != EXIT) {
        menu();
        while (gs != LEAVE) {
            if (mm == PLAY) {
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
                            printf("You have this Cards: \n");
                            p->showAllCards(checkMain);
                        } else if (po == HIT) {
                            draw(checkMain);
                            p->showAllCards(checkMain);
                            checkEarlyVictoryCondidtion(checkMain);
                        } else if (po == STAND) {
                            if (p->playerHasSplit() && checkMain) {
                                checkMain = false;
                                ps = static_cast<playerStatus>(3);
                            } else {
                                printf("You:\n");
                                p->printValue(checkMain);
                                gs = static_cast<gameState>(4);
                            }
                        }
                    }
                }
                if (ps == DNF) {
                    //dealer phase
                    printf("The Dealer has this cards: \n");
                    d->showAllCards(true);


                    while (d->getValue(true) < bjR->getDealerMaxPoints()) {
                        printf("\n \nThe dealer draws one Card and has now: \n");
                        draw(true);
                        d->showAllCards(true);
                    }
                    while (d->getValue(true) < bjR->getDealerMaxPoints()) {
                        draw(true);
                        d->showAllCards(true);
                    }
                    printf("\nDealer:\n");
                    d->printValue();


                    //cashout

                    bool exit = false;
                    bool checkMain = true;
                    bool dealerLoss = false;

                    if (d->getValue(true) > 21) {
                        dealerLoss = true;
                    }

                    while (!exit) {
                        if (dealerLoss) {
                            if (p->getValue(checkMain) <= 21) {
                                p->payWinSum(checkMain);
                                bjR->playerWin();
                            } else {
                                p->collectBet(checkMain);
                                bjR->playerLoose();
                            }
                        } else {
                            if (p->getValue(checkMain) < d->getValue(true)) {
                                p->collectBet(checkMain);
                                bjR->playerLoose();
                            } else if (p->getValue(checkMain) == d->getValue(true)) {
                                p->giveBetBack(checkMain);
                                bjR->playerTie();
                            } else if (p->getValue(checkMain) > d->getValue(true)) {
                                p->payWinSum(checkMain);
                                bjR->playerWin();
                            }
                        }
                        if (p->playerHasSplit()) {
                            checkMain = false;
                        } else {
                            exit = true;
                        }
                    }
                }
                p->resetHand();
                d->resetHand();
                kickPlayerIfBroke();
                playAnotherRound();
            } else if (mm == RULES) {
                bjR->printRules();
            }
        }
    }
    exitGame();

}

void blackJack::drawInitialCards() {
    for (int i = 0; i < 2; i++) {
        p->givePlayercard(cD.playFirstCardFromStack(), true);
        d->givePlayercard(cD.playFirstCardFromStack(), true);
    }

}

void blackJack::kickPlayerIfBroke() {
    if (p->isBroke(bjR->getMinBet())) {
        mm = static_cast<mainMenu>(3);
        printf("Bouncer: You dont own enough Chips to play. You have to leave the Casino\n");
        exitGame();
    }
}

void blackJack::menu() {
    int in;
    bool invalid = true;

    while (invalid) {

        printf("Welcome to Blackjack\n");
        printf("Your options are:\n");
        printf("1 - Play\n");
        printf("2 - Rules\n");
        printf("3 - Exit\n");
        printf("Your choice: ");
        std::cin >> in;

        if (in < 1 || in > 3) {
            printf("Invalid Choice. Please enter again\n\n");
        } else {

            invalid = false;
        }
    }
    printf("\n\n");


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

    cD.reshuffelIfNeeded(bjR->getReshuffelTrigger());
}

void blackJack::showCards() {
    printf("\n\nThe open Card of the dealer is: \n");
    d->showFirstCard();

    printf("You have this Cards: \n");
    p->showAllCards(true);

}

void blackJack::playAnotherRound() {
    int in;
    printf("Do you want to play a new round?\n");

    printf("1 - yes\n");
    printf("Enter any Value to leave the table.");
    printf("Your choice: ");
    std::cin >> in;
    printf("\n\n");

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

        printf("\n\nYour options are\n");

        if (p->canPlayerSplit()) {
            printf("0 -> split\n");
            p->setHasSplit();
        }

        printf("1 -> hit\n");
        printf("2 -> stand\n");
        printf("Your choice: ");
        std::cin >> in;

        if ((in == 0 && !p->playerHasSplit()) || in < 0 || in > 2) {
            printf("Invalid Choice. Please enter again\n");
        } else {

            invalid = false;
        }
    }
    printf("\n\n");

    po = static_cast<playerOption>(in);

}

void blackJack::checkEarlyVictoryCondidtion(bool checkMain) {
    if (p->getValue(checkMain) == 21) {
        ps = static_cast<playerStatus>(0);
        gs = static_cast<gameState>(2);
        bjR->playerWin();
    } else if (p->getValue(checkMain) > 21) {
        ps = static_cast<playerStatus>(1);
        gs = static_cast<gameState>(2);
        bjR->playerLoose();
    }
}

blackJack::blackJack(nullptr_t pVoid) {

}

