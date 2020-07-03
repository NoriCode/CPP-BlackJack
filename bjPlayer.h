#ifndef CCPP_EXAM_BJPLAYER_H
#define CCPP_EXAM_BJPLAYER_H


#include "bjCards.h"
#include "bjHand.h"

class bjPlayer {
private:
    bjPlayer();

    bjHand playerCards;

    int chips = 0;

public:
    explicit bjPlayer(int c = 0) : chips(c) {

        playerCards = bjHand();
    };

    void resetHand();

    bool isBroke(int min) const;

    void payWinSum();

    void collectBet();

    void giveBetBack();

    void showAllCards();

    void givePlayercard(std::shared_ptr<bjCards> card);

    void bet(int bet);

    int getChips() const;

    void showFirstCard();

    int getValue(bool player);

    void printValue(bool player);
};


#endif //CCPP_EXAM_BJPLAYER_H
