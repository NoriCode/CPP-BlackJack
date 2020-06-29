//
// Created by philip_nori on 29.06.20.
//

#ifndef CCPP_EXAM_BLACKJACK_H
#define CCPP_EXAM_BLACKJACK_H

#include "playCardDeck.h"
#include "bjRuleController.h"
#include "bjplayer.h"
#include "bjNonPlayer.h"
#include "bjCards.h"
#include "bjHand.h"


class blackJack {

private:
    enum playerOption {
        SPLIT = 0, HIT, STAND, LEAVE
    };

    enum gameState {
        NEWGAME = 0, PLAYMAIN, PLAYSPLIT
    };

    enum mainMenu {
        PLAY = 1, RULES, EXIT
    };


    gameState gs;
    playerOption po;
    mainMenu mm;


    bjHand main;
    bjHand split;

    bjRuleController *bjR = bjRuleController::getInstance();
    playCardDeck pCD;



    bjplayer *p = new bjplayer(bjR->getInitChips());
    bjNonPlayer *d = new bjNonPlayer();




    void newGame();

public:

    void menu();

    void game();

    void draw();

    void kickPlayer();

    bool exitGame();

    bool leaveTable();

};


#endif //CCPP_EXAM_BLACKJACK_H
