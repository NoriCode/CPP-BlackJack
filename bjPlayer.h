#ifndef CCPP_EXAM_BJPLAYER_H
#define CCPP_EXAM_BJPLAYER_H


#include "bjCards.h"
#include "bjHand.h"

class bjPlayer {
private:
    bjPlayer();

    bjHand firstDeck;
    bjHand split;

    int chips = 0;

    bool hasSplit = false;

public:
    explicit bjPlayer(int c = 0) : chips(c) {
        if (chips != 0) {
            split = new bjHand();
        }
        firstDeck = new bjHand();
    };

    bool canPlayerSplit();

    void splitCards();

    void bet(int min, int max);

    int getValue(bool checkFirst);

    void resetHand();

    bool isBroke(int min);

    void payWinSum(bool checkFirst);

    void collectBet(bool checkFirst);

    void giveBetBack(bool checkFirst);

    void showAllCards(bool checkFirst);

    bool playerHasSplit();

    void givePlayercard(std::shared_ptr<bjCards> card, bool checkFirst);

    void setHasSplit();

    void printValue(bool checkFirst);

};


#endif //CCPP_EXAM_BJPLAYER_H
