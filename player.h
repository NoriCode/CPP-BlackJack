//
// Created by philip_nori on 28.06.20.
//

#ifndef CCPP_EXAM_PLAYER_H
#define CCPP_EXAM_PLAYER_H


#include "cards.h"
#include "bjCards.h"
#include <vector>
#include "playerdeck.h"
#include "bjRuleController.h"


class player {
protected:

public:


    void giveMainCard(bjCards *card);

    int mainValue();

    void showCards();

    void showCards(std::string name);

    void resetMainDeck();
};


#endif //CCPP_EXAM_PLAYER_H
