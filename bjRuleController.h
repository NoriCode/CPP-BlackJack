#ifndef CCPP_EXAM_BJRULECONTROLLER_H
#define CCPP_EXAM_BJRULECONTROLLER_H

#include <iostream>

class bjRuleController {
private:
    /* Here will be the instance stored. */
    static bjRuleController *instance;

    /* Private constructor to prevent instancing. */
    bjRuleController();

    int _dealerMaxPoints = 17;
    int _blackjack = 21;
    double _returnValue = 1.5;
    int _playerBet;
    int _reshuffelTrigger = 75;
    int _numberOfDecks = 6;
    int _initChips = 1000;
    int minBet = 2;
    int maxBet = 500;


public:
    static bjRuleController *getInstance();

    static void printRules();

    int getDealerMaxPoints() const;

    void setDealerMaxPoints(int dealerMaxPoints);

    int getBlackjack() const;

    void setBlackjack(int blackjack);

    double getReturnValue() const;

    void setReturnValue(double returnValue);

    int getPlayerBet() const;

    void setPlayerBet(int playerBet);

    int getReshuffelTrigger() const;

    void setReshuffelTrigger(int reshuffelTrigger);

    int getNumberOfDecks() const;

    void setNumberOfDecks(int numberOfDecks);

    int getInitChips();

    int getMinBet();

    int getMaxBet();

    void playerWin();

    void playerLoose();

    void playerTie();

    int oneEleven();


    bool roundEndChecker();
};


#endif //CCPP_EXAM_BJRULECONTROLLER_H
