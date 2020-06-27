#include <stdio.h>
#include "playCardDeck.h"
#include "bjRuleController.h"
#include "player.h"

int menu() {
    int in;
    printf("Welcome to Blackjack\n");
    printf("Your options are:\n");
    printf("1 - Play\n");
    printf("2 - Rules\n");
    printf("3 - Exit\n");
    printf("Your choice: ");
    std::cin >> in;
    return in;
}

int playerOptions(int in, bool canSplit, bool hasSplit) {
    bool invalid = true;


    while (invalid) {
        printf("Your options are\n");

        if (canSplit) {
            printf("0 -> split\n");
        }

        printf("1 -> hit\n");
        printf("2 -> stand\n");
        printf("3 -> leave table\n");
        printf("Your choice: ");
        std::cin >> in;

        if ((in == 0 && !canSplit) || in > 3) {
            printf("Invalid Choice. Please enter again\n");
        } else {
            invalid = false;
        }
    }
    return in;
}

void kickPlayer(int pChips, int minChips) {
    if (pChips < minChips) {
        printf("Bouncer: You dont own enough Chips to play. You have to leave the Casino\n");
        exit(1);
    }
}

int game() {
    int playerChoice = 2;
    bjRuleController *bjR = bjRuleController::getInstance();
    playCardDeck pCD;
    player *p = new player(bjR->getInitChips());

    pCD.generatePlayDeck(bjR->getNumberOfDecks());

    // kickPlayer(0,1);

    for()

    while (playerChoice != 3) {
        bool leftPlayed, rightPlayed;

        kickPlayer(p->getChips(), bjR->getMinBet());

        if (pCD.getCardCounter() <= bjR->getReshuffelTrigger()) {
            pCD.deckShuffel();
        }

        p->bet(bjR->getMinBet(), bjR->getMaxBet());

        playerChoice = playerOptions(0, p->canSplit(), p->hasSplited());

        if (playerChoice == 0) {
            p->split();

        }

        if (leftPlayed) {
            if (playerChoice == 1) {
                p->giveLeftCard(pCD.getCardX(0));
                //  p->giveLeftCard(new bjCards("heart", "A", 11));
                pCD.playedCardsCollector(pCD.getCardX(0));
                p->leftValue();
            } else if (playerChoice == 2) {
                leftPlayed = true;
            }

            if (p->leftValue() == 21) {
                p->payout(p->getBetAmount() / 2);
                leftPlayed = true;
            } else if (p->leftValue() > 21 && p->hasSplited()) {
                p->halfBetamount();
                leftPlayed = true;
            }
        } else if (p->hasSplited() && !rightPlayed) {

            if (playerChoice == 1) {
                p->giveRightCard(pCD.getCardX(0));
                //  p->giveLeftCard(new bjCards("heart", "A", 11));
                pCD.playedCardsCollector(pCD.getCardX(0));
                p->rightValue();
            } else if (playerChoice == 2) {
                rightPlayed = true;
            }

            if (p->rightValue() == 21) {
                p->payout(p->getBetAmount() / 2);

                rightPlayed = true;
            } else if (p->rightValue() > 21 && p->hasSplited()) {
                p->halfBetamount();

                rightPlayed = true;
            }
        }

    }


    printf("Good Bye\n");

    pCD.resetPlayDeck();

    return 0;
}

int main() {

    int menuOption = 0;
    while (menuOption != 3) {
        menuOption = menu();
        if (menuOption == 1) {
            game();
        } else if (menuOption == 2) {
            bjRuleController::printRules();
        }
    }
    return 0;
}
