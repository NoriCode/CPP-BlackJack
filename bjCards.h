//
// Created by philip_nori on 19.06.20.
//

#ifndef CCPP_EXAM_BJCARDS_H
#define CCPP_EXAM_BJCARDS_H

#include <stdio.h>
#include <iostream>

class bjCards {
protected:
    int value;
    std::string number;
    std::string symbol;

public:
    explicit bjCards(std::string s = "nori", std::string n = "0", int v = 0) : symbol(s), number(n), value(v) {}

    void setValue(int v);

    int getValue();

    int whoAmI();

    std::string getnumber();

};


#endif //CCPP_EXAM_BJCARDS_H
