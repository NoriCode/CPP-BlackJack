#include "bjplayer.h"
#include "stdio.h"

void bjplayer::split() {
    giveSplitCard(left.getCardX(1));
    hasSplit = true;
    betAmount *= 2;
}

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
    betAmount = playerBet;
}


void bjplayer::giveSplitCard(bjCards *card) {
    splitDeck.addPlayDeck(card);
    printf("%i", mainValue());
    //todo karten genau anzeigen nicht nur wert
}

int bjplayer::splitValue() {
    return splitDeck.getTotalValue();
}

bool bjplayer::canSplit() {
    return splitAllowed;
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

int bjplayer::getBetAmount() {
    return betAmount;
}

void bjplayer::payout(int bet) {
    chips += (int) bet * 1.5;
}

void bjplayer::resetBetamount() {
    betAmount = 0;
}

void bjplayer::halfBetamount() {
    betAmount /= 2;
}

playerdeck bjplayer::getMainDeck() {
    return _mainDeck;
}

playerdeck bjplayer::getSplitDeck() {
    return splitDeck;
}

void bjplayer::repayBet() {
    chips += betAmount;
    resetBetamount();
}

void bjplayer::repayBet(int betAmount) {
    chips += betAmount;
    halfBetamount();
}

void bjplayer::ResetSplitDeck() {
    splitDeck.getDeck().clear();
}
