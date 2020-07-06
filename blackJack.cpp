//Topic 14:  Object Orientation: Interface vs. Implementation *

#include "blackJack.h"
#include <regex>

void blackJack::game() {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    while (mm != EXIT) {
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        if (gs == LEAVE) {
            menu();
        }
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        if (mm == EXIT) {
            return;
        }
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        if (mm == PLAY) {

            //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
            if (gs == NEWGAME) {
                newGame();
                gs = PLAYING;
            }

            //bet
            printDivider();
            bet();

            //spieler und dealer bekommen Karte P,D,P,D
            drawInitialCards();
            printDivider();
            //spieler: hit stand loop unterbrochen durch 21 oder höher
            {

                //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
                while (gs == PLAYING) {
                    //karten werden gedreht
                    showCards();

                    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
                    if (p->getValue(true) >= 21) {
                        po = static_cast<playerOption>(2);
                        gs = static_cast<gameState>(2);

                        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
                        if (p->getValue(true) == 21) {
                            printf("\n\n\n\n******************************************\n");
                            printf("You have a BlackJack\n");
                            printf("******************************************\n");
                        } else {
                            printf("\n\n\n\n******************************************\n");
                            printf("\nYou have over 21.\n");
                            printf("\n\n\n\n******************************************\n");
                        }
                        printf("\nYour turn ends automaticly.\n");
                        break;
                    }
                    playerRoundOptions();

                    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
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
            printf("\n\n\n\n------------------------------------------\n");
            printf("Dealer Turn\n");
            printf("------------------------------------------\n");

            printf("The Dealer has this cards: \n");
            d->showAllCards();


            //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
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


            //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
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
            printDivider();
            playAnotherRound();
        } else if (mm == RULES) {
            bjRuleController::printRules();
            gs = static_cast<gameState>(2);
            po = static_cast<playerOption>(4);
            mm = static_cast<mainMenu>(4);
            ps = static_cast<playerStatus>(2);
        }
    }
}

void blackJack::drawInitialCards() {
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    for (int i = 0; i < 2; i++) {
        p->givePlayercard(cD.playFirstCardFromStack());
        d->givePlayercard(cD.playFirstCardFromStack());
    }

}

void blackJack::kickPlayerIfBroke() {

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (p->isBroke(bjR->getMinBet())) {
        mm = static_cast<mainMenu>(3);
        printf("\nBouncer: You dont own enough Chips to play. You have to leave the Casino\n");
        exit(1);
    }

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (mm == EXIT) {
        exit(0);
    }
}

void blackJack::menu() {
    std::string in;
    int correctIn;
    std::regex regexPattern("-?[0-9]+.?[0-9]+");

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    do {
        printf("Welcome to Blackjack\n");
        printf("Your options are:\n");
        printf("1 - Play\n");
        printf("2 - Rules\n");
        printf("3 - Exit\n");
        printf("Your choice: ");
        std::cin >> in;
        correctIn = inputcheck(in);


        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        if (correctIn <= 3 && correctIn >= 1) {
            break;
        }
    } while (true);
    printf("\n\n");


    mm = static_cast<mainMenu>(correctIn);
    gs = static_cast<gameState>(1);
    po = static_cast<playerOption>(4);
    ps = static_cast<playerStatus>(4);
}


void blackJack::newGame() {
    cD.generatePlayCardsAndAddtoDeck(bjR->getNumberOfDecks());

    cD.reshuffelIfNeeded(bjR->getReshuffelTrigger());
}

void blackJack::showCards() {
    printf("The open Card of the dealer is: \n");
    d->showFirstCard();

    printf("You have this Cards: \n");
    p->showAllCards();

}

void blackJack::playAnotherRound() {
    std::string in;
    int correctIn;
    printf("Do you want to play a new round?\n");
    printf("Any other Value brings you to the menu. \n");


    printf("1 - yes\n");

    printf("Your choice: ");
    std::cin >> in;
    correctIn = inputcheck(in);


    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (correctIn != 1) {
        correctIn = 2;
    }

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    for (int i = 0; i < 100; ++i) {
        printf("\n\n");
    }
    gs = static_cast<gameState>(correctIn);
}

void blackJack::draw() {

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (po == HIT) {
        p->givePlayercard(cD.playFirstCardFromStack());
    } else if (po == STAND) {
        d->givePlayercard(cD.playFirstCardFromStack());
    }
}

void blackJack::playerRoundOptions() {
    std::string in;

    int correctIn;
    do {
        printf("\n\nYour options are\n");

        printf("1 -> hit\n");
        printf("2 -> stand\n");
        printf("Your choice: ");
        std::cin >> in;
        correctIn = inputcheck(in);


        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        if (correctIn <= 2 && correctIn >= 1) {
            break;
        }
    } while (true);

    printf("\n\n");

    //Topic 6: Daten : Umwandlung
    po = static_cast<playerOption>(correctIn);

}

blackJack::blackJack(std::nullptr_t) {}

blackJack::blackJack() = default;

void blackJack::printDivider() {
    printf("\n\n\n\n------------------------------------------\n");
    printf("\t\tNext Action\n");
    printf("------------------------------------------\n");
}

int blackJack::inputcheck(std::string in) {
    std::regex regexPattern("-?[0-9]");
    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    while (!regex_match(in, regexPattern)) {
        wrongInput();
        std::cin >> in;
    }
    return std::stoi(in);
}

void blackJack::wrongInput() {
    printf("\n------------------------------------------\n");
    printf("You have entered an Invalid Number\n");
    printf("------------------------------------------\n");
    printf("Please enter again:\n");
}

void blackJack::bet() {
    int playerBet;
    std::string in;

    //Topic 4: Daten: Darstellung
    printf("You have %i chips, place your bet.\n", p->getChips());
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
    printf("%i", playerBet);

    p->bet(playerBet);
}
