#ifndef CCPP_EXAM_BJRULECONTROLLER_H
#define CCPP_EXAM_BJRULECONTROLLER_H

#include <iostream>

class bjRuleController {
private:

    int dealerMaxPoints;
    int reshuffelTrigger;
    int numberOfDecks;
    int initChips;
    int minBet;
    int maxBet;


public:
    bjRuleController();

    static void printRules();

    static void playerWin();

    static void playerLoose();

    static void playerTie();

    int getDealerMaxPoints() const;

    int getReshuffelTrigger() const;

    int getNumberOfDecks() const;

    int getInitChips() const;

    int getMinBet() const;

    int getMaxBet() const;

};


#endif //CCPP_EXAM_BJRULECONTROLLER_H
