//Topic 14:  Object Orientation: Interface vs. Implementation *

#ifndef CCPP_EXAM_BJHAND_H
#define CCPP_EXAM_BJHAND_H

#include "bjCards.h"
#include "bjDeck.h"

//Topic 5: Daten: Datentypen
class bjHand {
private:
    int betAmount{};
    bjDeck deck;
public:

    bjHand();

    int givePlayerBetBack() const;

    void resetBetamount();

    void giveCard(const std::shared_ptr<bjCards> &card);

     int payout() const;

    void showcards();

    void showfirstCard();

    int getPlayerTotalvalue(bool player);

    void showValue(bool player);

    void bet(int playerBet);
};


#endif //CCPP_EXAM_BJHAND_H
