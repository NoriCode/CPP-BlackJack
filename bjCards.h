//Topic 14:  Object Orientation: Interface vs. Implementation *
#ifndef CCPP_EXAM_BJCARDS_H
#define CCPP_EXAM_BJCARDS_H

#include <cstdio>
#include <iostream>
#include <utility>
#include "playingCard.h"

//Topic 13: Object Orientation: Inheritance
class bjCards : public playingCard {
private:
    int value;

public:
    //Topic 26: Häufige fehlerquellen -> keine Uninitialisierten variablen
    explicit bjCards(std::string s = "nori", std::string n = "0", int v = 0) : playingCard(std::move(s), std::move(n)),
                                                                               value(v) {}

    void setValue(int v);

    int getValue() const;

    void whoAmI() override;

};


#endif //CCPP_EXAM_BJCARDS_H
