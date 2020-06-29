//
// Created by philip_nori on 19.06.20.
//

#include "bjCards.h"

void bjCards::setValue(int v) {
    value = v;
}

int bjCards::getValue() {
    return value;
}

int bjCards::whoAmI() {
    printf("%s, %s \n", symbol.c_str(), number.c_str());
    return 0;
}

std::string bjCards::getnumber() {
    return number;
}
