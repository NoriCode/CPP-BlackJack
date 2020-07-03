#ifndef CCPP_EXAM_BLACKJACK_H
#define CCPP_EXAM_BLACKJACK_H

#include "bjRuleController.h"
#include "bjCards.h"
#include "bjHand.h"
#include "bjDeck.h"
#include "bjPlayer.h"
#include "old_code_thats_for_future_project/bjDealer.h"


class blackJack {

private:
    blackJack();

    explicit blackJack(std::nullptr_t pVoid);

    enum playerOption {
        HIT = 1, STAND
    };

    enum gameState {
        NEWGAME = 1, LEAVE, PLAYING
    };

    enum mainMenu {
        PLAY = 1, RULES, EXIT
    };

    enum playerStatus {
        VICTORY = 0,
        TIE,
        LOSS
    };

    gameState gs = static_cast<gameState>(2);
    playerOption po = static_cast<playerOption>(4);
    mainMenu mm = static_cast<mainMenu>(4);
    playerStatus ps = static_cast<playerStatus>(2);

    bjRuleController *bjR = new bjRuleController();
    bjDeck cD;


    bjPlayer *p = new bjPlayer(bjR->getInitChips());
    bjPlayer *d = new bjPlayer(0);
    // bjDealer *d = new bjDealer();


    void newGame();

    void drawInitialCards();

    void draw();

    void menu();

    void showCards();

    void playAnotherRound();

    void playerRoundOptions();

    void kickPlayerIfBroke();

    void exitGame();

    void checkEarlyVictoryCondidtion();

    void bet();


public:
    // explicit blackJack(bjRuleController *pController) : bjR() {    }

    static blackJack *getInstance() {
        static blackJack s(nullptr);
        return &s;
    }

    blackJack(const blackJack &) = delete;

    void operator=(const blackJack &) = delete;


    void game();

    void leave();

    static void printDivider();

    static int inputcheck(std::string in);

    static void wrongInput();
};


#endif //CCPP_EXAM_BLACKJACK_H
