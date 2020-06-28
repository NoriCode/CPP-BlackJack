#ifndef CCPP_EXAM_BJPLAYER_H
#define CCPP_EXAM_BJPLAYER_H

#include "cards.h"
#include "bjCards.h"
#include <vector>
#include "playerdeck.h"
#include "bjRuleController.h"
#include "player.h"


class bjplayer : public player{
private:
    playerdeck left;
    playerdeck splitDeck;
    int chips;
    int betAmount;
    bool splitAllowed;
    bool hasSplit;

    int splitBet(int bet, int min, int max);


public:
    explicit bjplayer(int c = 0) : chips(c) {}

    bool canSplit();

    void split();

    void bet(int min, int max);

    void giveSplitCard(bjCards *card);

    int splitValue();

    int getChips();

    bool hasSplited();

    void blackjack();

    int getBetAmount();

    void resetBetamount();

    void halfBetamount();

    void payout(int bet);

    playerdeck getMainDeck();

    playerdeck getSplitDeck();

    void repayBet();

    void repayBet(int betAmount);

    void ResetSplitDeck();


};


#endif //CCPP_EXAM_BJPLAYER_H
