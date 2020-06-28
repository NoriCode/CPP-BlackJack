//
// Created by philip_nori on 19.06.20.
//

#include "bjCards.h"

void bjCards::setValue(int v) {
    _value = v;
}

int bjCards::getValue() {
    return _value;
}

int bjCards::whoAmI() {
    getValue();
    getSymbol();
    getnumber();
    printf("%s, %s, %i \n", getSymbol().c_str(), getnumber().c_str(), getValue());
    return 0;
}