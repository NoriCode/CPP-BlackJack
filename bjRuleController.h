#ifndef CCPP_EXAM_BJRULECONTROLLER_H
#define CCPP_EXAM_BJRULECONTROLLER_H

#include <iostream>

class bjRuleController {
private:
    /*
    /* Here will be the instance stored. */
  //  static bjRuleController *instance;


    /* Private constructor to prevent instancing.
    bjRuleController();
*/

    int dealerMaxPoints = 17;
    int reshuffelTrigger = 75;
    int numberOfDecks = 6;
    int initChips = 1000;
    int minBet = 2;
    int maxBet = 500;


public:
    // static bjRuleController *getInstance();

    bjRuleController();

    static void printRules();

    void playerWin();

    void playerLoose();

    void playerTie();

    int getDealerMaxPoints() const;

    int getReshuffelTrigger() const;

    int getNumberOfDecks() const;

    int getInitChips() const;

    int getMinBet() const;

    int getMaxBet() const;

};


#endif //CCPP_EXAM_BJRULECONTROLLER_H
