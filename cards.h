#ifndef CCPP_EXAM_CARDS_H
#define CCPP_EXAM_CARDS_H

#include <stdio.h>
#include <string>


class cards {
protected:
    std::string _number;
    std::string _symbol;
public:
    cards(std::string s = "nori", std::string n = "x") : _symbol(s), _number(n) {}

    virtual int whoAmI() = 0;

    void setSymbol(std::string s);

    void setnumber(char n);

    std::string getSymbol();

    std::string getnumber();

};


#endif //CCPP_EXAM_CARDS_H
