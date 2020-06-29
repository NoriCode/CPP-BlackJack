#ifndef CCPP_EXAM_BJRULECONTROLLER_H
#define CCPP_EXAM_BJRULECONTROLLER_H

#include <iostream>

class bjRuleController {
private:
    /* Here will be the instance stored. */
    static bjRuleController *instance = nullptr;

    /* Private constructor to prevent instancing. */
    bjRuleController()= default;;

    bjRuleController ( const bjRuleController& );

    int dealerMaxPoints = 17;
    int blackjack = 21;
    double returnValue = 1.5;
    int playerBet;
    int reshuffelTrigger = 75;
    int numberOfDecks = 6;
    int initChips = 1000;
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

    int getInitChips() const;

    int getMinBet();

    int getMaxBet();

    void playerWin();

    void playerLoose();

    void playerTie();

    int oneEleven();
};


#endif //CCPP_EXAM_BJRULECONTROLLER_H
