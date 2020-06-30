
#include "bjPlayer.h"


void bjPlayer::givePlayercard(std::shared_ptr<bjCards> card, bool checkMain) {
    if (checkMain) {
        main.giveCard(card);
    } else {
        split.giveCard(card);
    }
}

void bjPlayer::splitCards() {
    split.giveCard(main.removeFirstCard());
    split.bet(main.getBetAmount());
    hasSplit = true;
}

void bjPlayer::bet(int min, int max) {
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
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else if (playerBet < min) {
            printf("You placed less chips than allowed.\n");
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else if (playerBet > max) {
            printf("You placed more chips than allowed.\n");
            printf("Place your bet again: ");
            std::cin >> playerBet;
        } else {
            wrongbet = false;
        }


    }
    chips -= playerBet;

    main.bet(playerBet);
}

int bjPlayer::getValue(bool checkMain) {
    if (checkMain) {
        return main.getPlayerTotalvalue();
    } else {
        return split.getPlayerTotalvalue();
    }
}


void bjPlayer::resetHand() {
    main = new bjHand();
    if (split.exist()) {
        split = new bjHand();
    }
}

bool bjPlayer::isBroke(int min) {
    return chips < min;
}

void bjPlayer::payWinSum(bool checkMain) {
    if (checkMain) {
        main.payout();
    } else {
        split.payout();
    };
}

void bjPlayer::collectBet(bool checkMain) {
    if (checkMain) {
        main.resetBetamount();
    } else {
        split.resetBetamount();
    };

}

void bjPlayer::giveBetBack(bool checkMain) {
    if (checkMain) {
        main.givePlayerBetBack();
    } else {
        split.givePlayerBetBack();
    };
}

void bjPlayer::showAllCards(bool checkMain) {
    if (checkMain) {
        main.showcards();
    } else {
        split.showcards();
    }
}

bool bjPlayer::playerHasSplit() {
    return hasSplit;
}

bool bjPlayer::canPlayerSplit() {
    return main.canSplit();
}

void bjPlayer::setHasSplit() {
    hasSplit = !hasSplit;
}

void bjPlayer::printValue(bool checkMain) {
    if (checkMain) {
        main.showValue();
    } else {
        split.showValue();
    }

}



