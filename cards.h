#ifndef CCPP_EXAM_CARDS_H
#define CCPP_EXAM_CARDS_H

#include <stdio.h>
#include <string>


class cards {
public:
    cards(std::string s ="nori", std::string n = "x") :_symbol(s), _number(n){}
    virtual int whoAmI() = 0;

    void setSymbol(std::string s) {
        _symbol = s;
    }

    void setnumber(char n) {
        _number = n;
    }

    std::string getSymbol() {
        return _symbol ;
    }

    std::string getnumber() {
        return _number;
    }

protected:
    std::string _number;
    std::string _symbol;
};


#endif //CCPP_EXAM_CARDS_H
