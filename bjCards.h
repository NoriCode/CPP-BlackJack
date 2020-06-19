//
// Created by philip_nori on 19.06.20.
//

#ifndef CCPP_EXAM_BJCARDS_H
#define CCPP_EXAM_BJCARDS_H

#include <stdio.h>
#include <iostream>
#include "cards.h"
#include "helpers/println.hpp"

class bjCards : public cards {
protected:
    int _value;
public:
    explicit bjCards(std::string symbol = "nori", std::string number = "0", int value = 0) : cards(symbol, number),
                                                                                       _value(value) {}

    void setValue(int v) {
        _value = v;
    }

    int getValue() {
        return _value;
    }

    int whoAmI() override {
        getValue();
        getSymbol();
        getnumber();
        //std::cout << "Follow this command: " << getSymbol().c_str();
        printf("%s,%s,%i \n", getSymbol().c_str(), getnumber().c_str(), getValue());
        // std::cout << getSymbol(), getnumber(), getValue();
        //println(getSymbol().c_str(),getnumber(),getValue());
        return 0;
    }
};


#endif //CCPP_EXAM_BJCARDS_H
