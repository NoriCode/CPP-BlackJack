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

int kickPlayer(int pChips, int minChips) {
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

    while (playerChoice != 3) {
        if (pCD.getCardCounter() <= bjR->getReshuffelTrigger()) {
            pCD.deckShuffel();
        }

        p->bet(bjR->getMinBet(), bjR->getMaxBet());

        playerChoice = playerOptions(0, p->canSplit(), p->hasSplited());

        if (playerChoice == 0) {
            p->split();
        }


        if (playerChoice == 1) {
            p->giveLeftCard(pCD.getCardX(0));
            //  p->giveLeftCard(new bjCards("heart", "A", 11));
            pCD.playedCardsCollector(pCD.getCardX(0));
            p->leftValue();
        }

        if (p->leftValue() == 21) {

            //todo give player  bet
        } else if (p->leftValue() > 21) {
            //todo end turn
        }


        //  kickPlayer(p->getChips(), bjR->getMinBet());
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
