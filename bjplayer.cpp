#include "bjplayer.h"
#include "stdio.h"


void bjplayer::bet(int min, int max) {
    int playerBet = 0;
    int correctBet = 0;
    printf("You have %i chips, place your bet.\n", chips);
    printf("Your minimum bet is %i\n", min);
    printf("Your maximum bet is %i\n", max);
    printf("Place your bet: ");
    std::cin >> playerBet;
    correctBet = splitBet(playerBet, min, max);

    while (correctBet != 0) {

        printf("Place your bet again: ");
        std::cin >> playerBet;
        correctBet = splitBet(playerBet, min, max);
    }
    chips -= playerBet;
    //betAmount = playerBet;
}


int bjplayer::getChips() {
    return chips;
}

int bjplayer::splitBet(int bet, int min, int max) {
    if (bet > chips) {
        printf("You placed more chips than you own.\n");
        return 1;
    } else if (bet < min) {
        printf("You placed less chips than allowed.\n");
        return 2;
    } else if (bet > max) {
        printf("You placed more chips than allowed.\n");
        return 3;
    }
    return 0;
}

bool bjplayer::hasSplited() {
    return hasSplit;
}


void bjplayer::blackjack() {
    printf("You have Blackjack\n");

}


void bjplayer::payout(int bet) {
    chips += (int) bet * 1.5;
}




