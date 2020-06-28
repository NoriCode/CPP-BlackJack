//
// Created by philip_nori on 28.06.20.
//

#ifndef CCPP_EXAM_BJNONPLAYER_H
#define CCPP_EXAM_BJNONPLAYER_H

#include "player.h"

class bjNonPlayer : public player {
protected:
    int hitLimit = 17;

public:
    explicit bjNonPlayer();

    void showHiddenCard();

    void showOPenCard();
};


#endif //CCPP_EXAM_BJNONPLAYER_H
