//Topic 14:  Object Orientation: Interface vs. Implementation *
#ifndef CCPP_EXAM_BLACKJACK_H
#define CCPP_EXAM_BLACKJACK_H

#include "bjRuleController.h"
#include "bjCards.h"
#include "bjHand.h"
#include "bjDeck.h"
#include "bjPlayer.h"
#include "enums.h"

class blackJack {

private:
    blackJack();

    //Topic 23: Design Patterns Signleton
    explicit blackJack(std::nullptr_t pVoid);

    //Topic 26: Häufige fehlerquellen -> keine Uninitialisierten variablen
    gameState gs = static_cast<gameState>(2);
    playerOption po = static_cast<playerOption>(4);
    mainMenu mm = static_cast<mainMenu>(4);
    playerStatus ps = static_cast<playerStatus>(2);

    bjRuleController *bjR = new bjRuleController();
    bjDeck cD;


    //Topic 17: Object Orientation: Object Lifecycle
    bjPlayer *p = new bjPlayer(bjR->getInitChips());
    bjPlayer *d = new bjPlayer(0);


    void newGame();

    void drawInitialCards();

    void draw();

    void menu();

    void showCards();

    void playAnotherRound();

    void playerRoundOptions();

    void kickPlayerIfBroke();

    void bet();


public:


    //Topic 23: Design Patterns Singleton
    static blackJack *getInstance() {
        static blackJack s(nullptr);
        return &s;
    }

    blackJack(const blackJack &) = delete;

    void operator=(const blackJack &) = delete;

    void game();

    static void printDivider();

    static int inputcheck(std::string in);

    static void wrongInput();
};


#endif //CCPP_EXAM_BLACKJACK_H
