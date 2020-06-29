#ifndef CCPP_EXAM_BLACKJACK_H
#define CCPP_EXAM_BLACKJACK_H

#include "replaced/playCardDeck.h"
#include "bjRuleController.h"
#include "replaced/bjplayer.h"
#include "replaced/bjNonPlayer.h"
#include "bjCards.h"
#include "bjHand.h"
#include "tempDeck.h"
#include "tempPlayer.h"


class blackJack {

private:
    blackJack() = default;

    enum playerOption {
        SPLIT = 0, HIT, STAND
    };

    enum gameState {
        NEWGAME = 1, LEAVE, PLAYING
    };

    enum mainMenu {
        PLAY = 1, RULES, EXIT
    };

    enum playerStatus {
        VICTORY = 0,
        DEFEAD,
        DNF
    };

    gameState gs ;
    playerOption po;
    mainMenu mm;
    playerStatus ps;

    bjRuleController *bjR;
    tempDeck cD;


    tempPlayer *p = new tempPlayer(bjR->getInitChips());
    tempPlayer *d;


    void newGame();

    void drawInitialCards();

    void draw(bool checkMain);

    void menu();

    void showCards();

    void playAnotherRound();

    void playerRoundOptions();

    void kickPlayerIfBroke();

    bool exitGame();

    bool leaveTable();

    void checkEarlyVictoryCondidtion(bool checkMain);


public:
   // explicit blackJack(bjRuleController *pController) : bjR() {    }

    static blackJack* instance() { static blackJack s; return &s; }
    blackJack(const blackJack&) = delete;
    void operator=(const blackJack&) = delete;


    void game();
};


#endif //CCPP_EXAM_BLACKJACK_H
