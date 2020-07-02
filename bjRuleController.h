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


    static void playerWin();

    static void playerLoose();

    static void playerTie();

public:
    bjRuleController();

    static void printRules();

    int getDealerMaxPoints() const;

    int getReshuffelTrigger() const;

    int getNumberOfDecks() const;

    int getInitChips() const;

    int getMinBet() const;

    int getMaxBet() const;

    int winLossTieControll(int pValue, int dValue);

};


#endif //CCPP_EXAM_BJRULECONTROLLER_H
