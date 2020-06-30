//
// Created by philip_nori on 29.06.20.
//

#ifndef CCPP_EXAM_BJHAND_H
#define CCPP_EXAM_BJHAND_H
#include "bjCards.h"
#include "replaced/playerdeck.h"
#include "tempDeck.h"

class bjHand {
private:
    int betAmount;
    tempDeck deck;
    bool splitAllowed = true;
    bool amIReal;
public:

    void split();

    int givePlayerBetBack();

    void resetDeck();

    void resetBetamount();

    void giveCard(std::shared_ptr<bjCards> card);

    bool canSplit();

    int getPlayerTotalvalue();


    int getBetAmount();

    int payout();

    std::shared_ptr<bjCards> removeFirstCard();

    void showcards();

    void bet(int playerBet);

    void clear();

    bool exist();

    void showfirstCard();

    bjHand(bjHand *pHand);

    bjHand();
};


#endif //CCPP_EXAM_BJHAND_H
