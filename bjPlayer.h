#ifndef CCPP_EXAM_BJPLAYER_H
#define CCPP_EXAM_BJPLAYER_H


#include "bjCards.h"
#include "bjHand.h"

class bjPlayer {
private:
    bjPlayer();

    bjHand main;
    bjHand split;

    int chips = 0;

    bool hasSplit = false;

public:
    explicit bjPlayer(int c = 0) : chips(c) {
        if (chips != 0) {
            split = new bjHand();
        }
        main = new bjHand();
    };

    bool canPlayerSplit();

    void splitCards();

    void bet(int min, int max);

    int getValue(bool checkMain);

    void resetHand();

    bool isBroke(int min);

    void payWinSum(bool checkMain);

    void collectBet(bool checkMain);

    void giveBetBack(bool checkMain);

    void showAllCards(bool checkMain);

    bool playerHasSplit();

    void givePlayercard(std::shared_ptr<bjCards> card, bool checkMain);

    void setHasSplit();

    void printValue(bool checkMain);

};


#endif //CCPP_EXAM_BJPLAYER_H
