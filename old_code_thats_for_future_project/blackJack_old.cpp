#include "blackJack_old.h"
#include "../bjRuleController.h"
#include <cstdio>
#include <regex>

void blackJack::game() {
    while (mm != EXIT) {
        menu();
        if (mm == EXIT) {
            gs = static_cast<gameState>(2);
        }
        while (gs != LEAVE) {
            if (mm == PLAY) {
                if (gs == NEWGAME) {
                    newGame();
                    gs = static_cast<gameState>(3);
                }

                //bet
                printDivider();
                p->bet(bjR->getMinBet(), bjR->getMaxBet());
                printDivider();

                //spieler und dealer bekommen Karte P,D,P,D
                drawInitialCards();
                //karten werden gedreht
                showCards();
                //spieler: hit stand loop unterbrochen durch 21 oder höher
                {
                    bool checkMain = true;
                    while (gs == PLAYING) {
                        playerRoundOptions();
                        printDivider();
                        if (po == SPLIT) {
                            p->splitCards();
                            printf("\nYou have this Cards: \n");
                            p->showAllCards(checkMain);
                        } else if (po == HIT) {
                            draw(checkMain);
                            printf("\nYou have this Cards: \n");
                            p->showAllCards(checkMain);
                            checkEarlyVictoryCondidtion(checkMain);
                        } else if (po == STAND) {
                            if (p->playerHasSplit() && checkMain) {
                                checkMain = false;
                                p->showAllCards(checkMain);
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
                    printf("\nThe Dealer has this cards: \n");
                    d->showAllCards(true);


                    while (d->getValue(true) < bjR->getDealerMaxPoints()) {
                        printf("\n \nThe dealer draws one Card and has now: \n");
                        draw(true);
                        d->showAllCards(true);
                    }
                    printf("\nDealer:\n");
                    d->printValue();


                    //cashout

                    bool exit = false;
                    bool checkFirst = true;
                    bool dealerLoss = false;

                    if (d->getValue(true) > 21) {
                        printf("debug");
                        dealerLoss = true;
                    }

                    while (!exit) {
                        if (dealerLoss) {
                            if (p->getValue(checkFirst) <= 21) {
                                p->payWinSum(checkFirst);
                                bjRuleController::playerWin();
                            } else {
                                p->collectBet(checkFirst);
                                bjRuleController::playerLoose();
                            }
                        } else {
                            if (p->getValue(checkFirst) < d->getValue(true)) {
                                p->collectBet(checkFirst);
                                bjRuleController::playerLoose();
                            } else if (p->getValue(checkFirst) == d->getValue(true)) {
                                p->giveBetBack(checkFirst);
                                bjRuleController::playerTie();
                            } else if (p->getValue(checkFirst) > d->getValue(true)) {
                                p->payWinSum(checkFirst);
                                bjRuleController::playerWin();
                            }
                        }
                        if (p->playerHasSplit()) {
                            checkFirst = false;
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
                bjRuleController::printRules();
                mm = static_cast<mainMenu>(4);
                gs = static_cast<gameState>(2);
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
        printf("\nBouncer: You dont own enough Chips to play. You have to leave the Casino\n");
        exit(1);
    }
    if (mm == EXIT) {
        exit(0);
    }
}

void blackJack::menu() {
    std::string in;
    int correctIn;
    std::regex regexPattern("-?[0-9]+.?[0-9]+");
    bool invalid = true;

    while (invalid) {

        printf("Welcome to Blackjack\n");
        printf("Your options are:\n");
        printf("1 - Play\n");
        printf("2 - Rules\n");
        printf("3 - Exit\n");
        printf("Your choice: ");
        std::cin >> in;
        correctIn = inputcheck(in);


        if (correctIn < 1 || correctIn > 3) {

            std::cin >> in;
            correctIn = inputcheck(in);
        } else {
            invalid = false;
        }
    }
    printf("\n\n");


    mm = static_cast<mainMenu>(correctIn);
    gs = static_cast<gameState>(1);
    po = static_cast<playerOption>(4);
    ps = static_cast<playerStatus>(2);
}

void blackJack::exitGame() {
    mm = EXIT;
}


void blackJack::newGame() {
    cD.generatePlayCardsAndAddtoDeck(bjR->getNumberOfDecks());

    cD.reshuffelIfNeeded(bjR->getReshuffelTrigger());
}

void blackJack::showCards() {
    printf("\nThe open Card of the dealer is: \n");
    d->showFirstCard();

    printf("You have this Cards: \n");
    p->showAllCards(true);

}

void blackJack::playAnotherRound() {
    std::string in;
    int correctIn;
    printf("Do you want to play a new round?\n");

    printf("1 - yes\n");
    printf("Enter any Value to leave the table.\n");
    printf("Your choice: ");
    std::cin >> in;
    correctIn = inputcheck(in);

    if (correctIn != 1) {
        in = 2;
    }
    gs = static_cast<gameState>(correctIn);
}

void blackJack::draw(bool checkFirst) {

    if (po == HIT) {
        p->givePlayercard(cD.playFirstCardFromStack(), checkFirst);
    } else if (po == STAND) {
        d->givePlayercard(cD.playFirstCardFromStack(), true);
    }
}

void blackJack::playerRoundOptions() {
    bool invalid = true;
    std::string in;
    int correctIn;

    printf("\n\nYour options are\n");

    if (p->canPlayerSplit()) {
        printf("0 -> split\n");
        p->setHasSplit();
    }

    printf("1 -> hit\n");
    printf("2 -> stand\n");
    printf("Your choice: ");
    std::cin >> in;
    correctIn = inputcheck(in);

    while ((correctIn == 0 && !p->playerHasSplit()) || correctIn < 0 || correctIn > 2) {
        correctIn = inputcheck(in);
    }

    printf("\n\n");

    po = static_cast<playerOption>(correctIn);

}

void blackJack::checkEarlyVictoryCondidtion(bool checkFirst) {
    if (p->getValue(checkFirst) == 21) {
        ps = static_cast<playerStatus>(0);
        gs = static_cast<gameState>(2);
        bjRuleController::playerWin();
        p->payWinSum(checkFirst);
    } else if (p->getValue(checkFirst) > 21) {
        ps = static_cast<playerStatus>(1);
        gs = static_cast<gameState>(2);
        bjRuleController::playerLoose();
        p->collectBet(checkFirst);
    }
}

blackJack::blackJack(std::nullptr_t) {}

blackJack::blackJack() = default;

void blackJack::printDivider() {
    printf("\n\n\n\n-------------------------------------\n");
    printf("New Action Required\n");
    printf("-------------------------------------");
}

int blackJack::inputcheck(std::string in) {
    std::regex regexPattern("-?[0-9]");
    while (!regex_match(in, regexPattern)) {
        wrongInput();
        std::cin >> in;
    }
    return std::stoi(in);
}

void blackJack::wrongInput() {
    printf("\n-------------------------------------\n");
    printf("Invalid Choice. Please enter again\n");
}

© 2020 GitHub, Inc.