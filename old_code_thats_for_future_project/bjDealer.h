#ifndef CCPP_EXAM_BJDEALER_H
#define CCPP_EXAM_BJDEALER_H


#include "../bjHand.h"

class bjDealer {
private:

    bjHand main;
public:
    explicit bjDealer() {
        main = new bjHand();
    }

    int getValue();

    void resetHand();

    void givePlayercard(std::shared_ptr<bjCards> card);

    void showFirstCard();

    void showAllCards(bool checkMain);

    void printValue();
};


#endif //CCPP_EXAM_BJDEALER_H
