
#include "../bjPlayer.h"
#include <cstdio>
#include <regex>

void bjPlayer::givePlayercard(std::shared_ptr<bjCards> card, bool checkFirst) {
    if (checkFirst) {
        firstDeck.giveCard(card);
    } else {
        split.giveCard(card);
    }
}

void bjPlayer::splitCards() {
    split.giveCard(firstDeck.removeFirstCard());
    split.bet(firstDeck.getBetAmount());
    hasSplit = true;
}

void bjPlayer::bet(int min, int max) {
    int playerBet = 0;
    bool wrongbet = true;
    std::string in;

    printf("\nYou have %i chips, place your bet.\n", chips);
    printf("Your minimum bet is %i\n", min);
    printf("Your maximum bet is %i\n", max);
    printf("Place your bet: ");
    std::cin >> in;

    std::regex regexPattern("-?[0-9]|[0-9][0-9]|[0-9][0-9][0-9]");
    while (!regex_match(in, regexPattern)) {
        printf("\n-------------------------------------\n");
        printf("Invalid Choice. Please enter again\n");
        std::cin >> in;
    }
    playerBet = std::stoi(in);


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

    firstDeck.bet(playerBet);
}

int bjPlayer::getValue(bool checkFirst) {
    if (checkFirst) {
        return firstDeck.getPlayerTotalvalue();
    } else {
        return split.getPlayerTotalvalue();
    }
}


void bjPlayer::resetHand() {
    firstDeck = new bjHand();
    if (split.exist()) {
        split = new bjHand();
    }
}

bool bjPlayer::isBroke(int min) {
    return chips < min;
}

void bjPlayer::payWinSum(bool checkFirst) {
    if (checkFirst) {
        chips += firstDeck.payout();
    } else {
        chips += split.payout();
    };
}

void bjPlayer::collectBet(bool checkFirst) {
    if (checkFirst) {
        firstDeck.resetBetamount();
    } else {
        split.resetBetamount();
    };

}

void bjPlayer::giveBetBack(bool checkFirst) {
    if (checkFirst) {
        chips += firstDeck.givePlayerBetBack();
    } else {
        chips += split.givePlayerBetBack();
    };
}

void bjPlayer::showAllCards(bool checkFirst) {
    if (checkFirst) {
        firstDeck.showcards();
    } else {
        split.showcards();
    }
}

bool bjPlayer::playerHasSplit() {
    return hasSplit;
}

bool bjPlayer::canPlayerSplit() {
    return firstDeck.canSplit();
}

void bjPlayer::setHasSplit() {
    hasSplit = !hasSplit;
}

void bjPlayer::printValue(bool checkFirst) {
    if (checkFirst) {
        firstDeck.showValue();
    } else {
        split.showValue();
    }

}



