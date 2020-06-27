//
// Created by philip_nori on 27.06.20.
//

#ifndef CCPP_EXAM_PLAYERDECK_H
#define CCPP_EXAM_PLAYERDECK_H

#include "deck.h"

class playerdeck : public deck {
protected:
    int totalValue;
public:
    int getTotalValue();
};


#endif //CCPP_EXAM_PLAYERDECK_H
