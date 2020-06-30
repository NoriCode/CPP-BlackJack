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
#include "bjDealer.h"


class blackJack {

private:
    blackJack(){    };

    blackJack(nullptr_t pVoid);

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

    gameState gs = static_cast<gameState>(1);
    playerOption po = static_cast<playerOption>(4);
    mainMenu mm  = static_cast<mainMenu>(4);
    playerStatus ps = static_cast<playerStatus>(2);

    bjRuleController *bjR = new bjRuleController();
    tempDeck cD;


    tempPlayer *p = new tempPlayer(bjR->getInitChips());
    bjDealer *d = new bjDealer();


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

    static blackJack* getInstance() { static blackJack s(nullptr); return &s; }
    blackJack(const blackJack&) = delete;
    void operator=(const blackJack&) = delete;


    void game();
};


#endif //CCPP_EXAM_BLACKJACK_H
