
#include "blackJack.h"
#include "bjRuleController.h"
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
                bet();

                //spieler und dealer bekommen Karte P,D,P,D
                drawInitialCards();
                printDivider();
                //spieler: hit stand loop unterbrochen durch 21 oder höher
                {
                    while (gs == PLAYING) {
                        //karten werden gedreht
                        showCards();
                        if (p->getValue(true) >= 21) {
                            po = static_cast<playerOption>(2);
                            gs = static_cast<gameState>(2);
                            if (p->getValue(true) == 21) {
                                printf("\nyou have a BlackJack\n");
                            } else {
                                printf("\nYou have over 21.\n");
                            }
                            printf("\nYour turn ends automaticly.\n");
                            break;
                        }
                        playerRoundOptions();
                        if (po == HIT) {
                            draw();
                            printf("\nYou have this Cards: \n");
                            p->showAllCards();

                            printDivider();
                        } else if (po == STAND) {
                            printf("\nYou:\n");
                            p->printValue(true);
                            gs = static_cast<gameState>(4);
                        }
                    }
                }
                //dealer phase
                printf("\n\n\n\n-------------------------------------\n");
                printf("Dealer Turn\n");
                printf("-------------------------------------");

                printf("\nThe Dealer has this cards: \n");
                d->showAllCards();


                while (d->getValue(false) < bjR->getDealerMaxPoints()) {
                    draw();
                    printf("\n \nThe dealer draws one Card and has now: \n");
                    d->showAllCards();
                }

                printf("\nYou:\n");
                p->printValue(true);

                printf("\nDealer:\n");
                d->printValue(false);

                //cashout
                ps = static_cast<playerStatus>(bjR->winLossTieControll(p->getValue(true), d->getValue(false)));

                if (ps == VICTORY) {
                    p->payWinSum();
                } else if (ps == TIE) {
                    p->giveBetBack();
                } else if (ps == LOSS) {
                    p->collectBet();
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
        p->givePlayercard(cD.playFirstCardFromStack());
        d->givePlayercard(cD.playFirstCardFromStack());
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
    ps = static_cast<playerStatus>(4);
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
    p->showAllCards();

}

void blackJack::playAnotherRound() {
    std::string in;
    int correctIn;
    printf("Do you want to play a new round?\n");

    printf("0- no\n");
    printf("1 - yes\n");

    printf("Your choice: ");
    std::cin >> in;
    correctIn = inputcheck(in);

    if (correctIn != 1) {
        in = 2;
    }
    gs = static_cast<gameState>(correctIn);
}

void blackJack::draw() {

    if (po == HIT) {
        p->givePlayercard(cD.playFirstCardFromStack());
    } else if (po == STAND) {
        d->givePlayercard(cD.playFirstCardFromStack());
    }
}

void blackJack::playerRoundOptions() {
    std::string in;
    int correctIn;

    printf("\n\nYour options are\n");

    printf("1 -> hit\n");
    printf("2 -> stand\n");
    printf("Your choice: ");
    std::cin >> in;
    correctIn = inputcheck(in);

    while (correctIn < 1 || correctIn > 2) {
        correctIn = inputcheck(in);
    }

    printf("\n\n");

    po = static_cast<playerOption>(correctIn);

}

void blackJack::checkEarlyVictoryCondidtion() {
    if (p->getValue(true) == 21) {
        ps = static_cast<playerStatus>(0);
        gs = static_cast<gameState>(2);
        // bjRuleController::playerWin();
        p->payWinSum();
    } else if (p->getValue(true) > 21) {
        ps = static_cast<playerStatus>(1);
        gs = static_cast<gameState>(2);
        //bjRuleController::playerLoose();
        p->collectBet();
    }
}

blackJack::blackJack(std::nullptr_t) {}

blackJack::blackJack() = default;

void blackJack::printDivider() {
    printf("\n\n\n\n-------------------------------------\n");
    printf("Next Action\n");
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
    printf("You have entered an Invalid Number\n");
    printf("Please enter again:\n");
}

void blackJack::bet() {
    int playerBet = 0;
    std::string in;

    printf("\nYou have %i chips, place your bet.\n", p->getChips());
    printf("Your minimum bet is %i\n", bjR->getMinBet());
    printf("Your maximum bet is %i\n", bjR->getMaxBet());
    printf("Place your bet: ");
    std::cin >> in;


//    std::regex regexPattern("-?[0-9]|[0-9][0-9]|[0-9][0-9][0-9]");
    std::regex regexPattern("[2-9]|[1-8][0-9]|9[0-9]|[1-4][0-9]{2}|500");
    while (!regex_match(in, regexPattern)) {
        wrongInput();
        std::cin >> in;
    }

    playerBet = std::stoi(in);
    // playerBet = inputcheck(in);
    printf("%i", playerBet);

/*
    while (wrongbet) {
        if (playerBet > p->getChips()) {
            printf("You placed more chips than you own.\n");
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else if (playerBet < bjR->getMinBet()) {
            printf("You placed less chips than allowed.\n");
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else if (playerBet > bjR->getMaxBet()) {
            printf("You placed more chips than allowed.\n");
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else {
            wrongbet = false;
        }


    }*/

    p->bet(playerBet);
}
