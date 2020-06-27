#include "player.h"
#include "stdio.h"

void player::split() {
    giveRightCard(left.getCardX(1));
    hasSplit = true;
    betAmount *= 2;
}

void player::bet(int min, int max) {
    int playerBet = 0;
    int correctBet = 0;
    printf("You have %i chips, place your bet.\n", chips);
    printf("Your minimum bet is %i\n", min);
    printf("Your maximum bet is %i\n", max);
    printf("Place your bet: ");
    std::cin >> playerBet;
    correctBet = rightBet(playerBet, min, max);

    while (correctBet != 0) {

        printf("Place your bet again: ");
        std::cin >> playerBet;
        correctBet = rightBet(playerBet, min, max);
    }
    chips -= playerBet;
    betAmount = playerBet;
}

void player::giveLeftCard(bjCards *card) {

    if (card->getSymbol().compare("A")) {
        card->setValue(oneEleven());
    }

    left.addPlayDeck(card);
    printf("%i", leftValue());
    //todo karten genau anzeigen nicht nur wert
}

void player::giveRightCard(bjCards *card) {
    right.addPlayDeck(card);
}

int player::rightValue() {
    return right.getTotalValue();
}

int player::leftValue() {
    return left.getTotalValue();
}

bool player::canSplit() {
    return splitAllowed;
}

int player::getChips() {
    return chips;
}

int player::rightBet(int bet, int min, int max) {
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

bool player::hasSplited() {
    return hasSplit;
}

int player::oneEleven() {
    int in;
    while (in != 1 && in != 11) {
        printf("You have drawn an Ace. You can decide if it has the value 1 or 11\n");
        printf("Which Value has your Ace: ");
        std::cin >> in;
    }
    return in;
}

void player::blackjack() {
    printf("You have Blackjack");

}

int player::getBetAmount() {
    return betAmount;
}

void player::payout(int bet) {
    chips += (int) bet * 1.5;
}

void player::resetBetamount() {
    betAmount = 0;
}

void player::halfBetamount() {
    betAmount /= 2;
}


