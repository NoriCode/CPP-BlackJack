
#ifndef CCPP_EXAM_BJHAND_H
#define CCPP_EXAM_BJHAND_H

#include "bjCards.h"
#include "bjDeck.h"

class bjHand {
private:
    int betAmount{};
    bjDeck deck;
    bool amIReal{};
public:


   bjHand(bjHand *pHand);

    bjHand();

    void split();

    int givePlayerBetBack() const;

    void resetBetamount();

    void giveCard(std::shared_ptr<bjCards> card);

    bool canSplit();

    int getPlayerTotalvalue();


    int getBetAmount() const;

    int payout() const;

    std::shared_ptr<bjCards> removeFirstCard();

    void showcards();

    void bet(int playerBet);

    void clear();

    bool exist() const;

    void showfirstCard();

    void showValue();

    void showHiddenCard();
};


#endif //CCPP_EXAM_BJHAND_H
