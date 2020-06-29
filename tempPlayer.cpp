//
// Created by nori on 29.06.20.
//

#include "tempPlayer.h"


void tempPlayer::givePlayercard(bjCards *card) {
    main.giveCard(card);
}

void tempPlayer::splitCards() {
    split.giveCard(main.removeFirstCard());
    split.bet(main.getBetAmount());
}

void tempPlayer::bet(int min, int max) {
    int playerBet = 0;
    bool wrongbet = true;
    printf("You have %i chips, place your bet.\n", chips);
    printf("Your minimum bet is %i\n", min);
    printf("Your maximum bet is %i\n", max);
    printf("Place your bet: ");
    std::cin >> playerBet;

    while (wrongbet) {
        if (playerBet > chips) {
            printf("You placed more chips than you own.\n");
        } else if (playerBet < min) {
            printf("You placed less chips than allowed.\n");
        } else if (playerBet > max) {
            printf("You placed more chips than allowed.\n");
        } else {
            wrongbet = false;
        }

        printf("Place your bet again: ");
        std::cin >> playerBet;
    }
    chips -= playerBet;

    main.bet(playerBet);
}

int tempPlayer::getValue(bool checkMain) {
    if (checkMain) {
        return main.getTotalvalue();
    } else {
        return split.getTotalvalue();
    }
}


void tempPlayer::resetHand() {
    main.resetBetamount();
    main.clear();
    if (split.exist()) {
        split.resetDeck();
        split.clear();
    }
}

bool tempPlayer::isBroke(int min) {
    return chips < min;
}

void tempPlayer::payWinSum(bool checkMain) {
    if (checkMain) {
        main.payout();
    } else {
        split.payout()
    };
}

void tempPlayer::collectBet(bool checkMain) {
    if (checkMain) {
        main.resetBetamount();
    } else {
        split.resetBetamount();
    };

}

void tempPlayer::giveBetBack(bool checkMain) {
    if (checkMain) {
        main.givePlayerBetBack();
    } else {
        split.givePlayerBetBack();
    };
}


int tempPlayer::getChips() {
    return chips;
}
