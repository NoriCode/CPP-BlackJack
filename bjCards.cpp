//Topic 14:  Object Orientation: Interface vs. Implementation *
#include "bjCards.h"

void bjCards::setValue(int v) {
    value = v;
}

int bjCards::getValue() const {
    return value;
}

void bjCards::whoAmI() {
    printf("%s, %s \n", getSymbol().c_str(), getNumber().c_str());
}