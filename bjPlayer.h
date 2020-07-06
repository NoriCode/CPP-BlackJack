//Topic 13:  Object Orientation: Inheritance
#ifndef CCPP_EXAM_BJPLAYER_H
#define CCPP_EXAM_BJPLAYER_H


#include "bjCards.h"
#include "bjHand.h"

class bjPlayer {
private:
    //Topic 26: Häufige fehlerquellen -> keine Uninitialisierten variablen
    bjPlayer();

    bjHand playerCards;

    int chips = 0;

public:
    explicit bjPlayer(int c = 0) : chips(c) {
        //Topic 17: Object Orientation: Object Lifecycle
        playerCards = bjHand();
    };

    void resetHand();

    bool isBroke(int min) const;

    void payWinSum();

    void collectBet();

    void giveBetBack();

    void showAllCards();

    void givePlayercard(const std::shared_ptr<bjCards> &card);

    void bet(int bet);

    int getChips() const;

    void showFirstCard();

    int getValue(bool player);

    void printValue(bool player);
};


#endif //CCPP_EXAM_BJPLAYER_H
