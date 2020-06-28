#include <cstdio>
#include "playCardDeck.h"
#include "bjRuleController.h"
#include "bjplayer.h"
#include "bjNonPlayer.h"

int menu() {
    int in;
    printf("Welcome to Blackjack\n");
    printf("Your options are:\n");
    printf("1 - Play\n");
    printf("2 - Rules\n");
    printf("3 - Exit\n");
    printf("Your choice: ");
    std::cin >> in;
    printf("\n");
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

        if ((in == 0 && !hasSplit) || in < 0 || in > 3) {
            printf("Invalid Choice. Please enter again\n");
        } else {
            invalid = false;
        }
    }
    printf("\n");
    return in;
}

void kickPlayer(int pChips, int minChips) {
    if (pChips < minChips) {
        printf("Bouncer: You dont own enough Chips to play. You have to leave the Casino\n");
        exit(1);
    }
}

int game() {
    int playerChoice = 0;
    bjRuleController *bjR = bjRuleController::getInstance();
    playCardDeck pCD;
    auto *p = new bjplayer(bjR->getInitChips());
    auto *d = new bjNonPlayer();

    bool leftPlayed = false;
    bool rightPlayed = false;

    while (playerChoice != 3) {
        pCD.generatePlayDeck(bjR->getNumberOfDecks());
        pCD.deckShuffel();
        for (int i = 0; i < 2; i++) {
            p->giveMainCard(pCD.giveOutCard());

            d->giveMainCard(pCD.giveOutCard());
        }

        kickPlayer(p->getChips(), bjR->getMinBet());

        if (pCD.getCardCounter() <= bjR->getReshuffelTrigger()) {
            pCD.deckShuffel();
        }
        printf("The open Card of the dealer is: ");
        d->showOPenCard();

        p->showCards("You");
        p->bet(bjR->getMinBet(), bjR->getMaxBet());


        playerChoice = playerOptions(0, p->canSplit(), p->hasSplited());

        if (playerChoice == 0) {
            p->split();
        }

        if (!leftPlayed) {
            if (playerChoice == 1) {
                p->giveMainCard(pCD.giveOutCard());
                pCD.playedCardsCollector(pCD.giveOutCard());
                p->mainValue();
            } else if (playerChoice == 2) {
                leftPlayed = true;
            }

            if (p->mainValue() == 21) {
                p->payout(p->getBetAmount() / 2);
                p->blackjack();
                leftPlayed = true;
            } else if (p->getMainDeck().getTotalValue() > 21) {
                p->halfBetamount();
                leftPlayed = true;
            }
        } else if (p->hasSplited() && !rightPlayed) {

            if (playerChoice == 1) {
                p->giveSplitCard(pCD.getCardX(0));
                pCD.playedCardsCollector(pCD.getCardX(0));
                p->splitValue();
            } else if (playerChoice == 2) {
                rightPlayed = true;
            }

            if (p->getSplitDeck().getTotalValue() == 21) {
                p->payout(p->getBetAmount() / 2);
                p->blackjack();
                rightPlayed = true;
            } else if (p->getSplitDeck().getTotalValue() > 21) {
                p->halfBetamount();
                rightPlayed = true;
            }
        }


        while (d->mainValue() < 17) {
            d->showCards("dealer");
            d->giveMainCard(pCD.giveOutCard());
        }
        if (p->hasSplited()) {
            if (d->mainValue() < p->getSplitDeck().getTotalValue()) {
                p->payout(p->getBetAmount() / 2);
            } else if (d->mainValue() == p->getSplitDeck().getTotalValue()) {
                p->repayBet(p->getBetAmount() / 2);
            }
        }
        if (d->mainValue() < p->getMainDeck().getTotalValue()) {
            p->payout(p->getBetAmount());
        } else if (d->mainValue() == p->getMainDeck().getTotalValue()) {
            p->repayBet();
        }
        p->resetBetamount();
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
