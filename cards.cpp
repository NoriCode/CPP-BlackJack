#include "cards.h"


#include "cards.h"

int cards::whoAmI() {
    printf("%s,%s", getSymbol().c_str(), getnumber().c_str());
    return 0;
}

void cards::setSymbol(std::string s) {
    _symbol = s;
}

void cards::setnumber(char n) {
    _number = n;
}

std::string cards::getSymbol() {
    return _symbol;
}

std::string cards::getnumber() {
    return _number;
}