#ifndef CCPP_EXAM_CARDS_H
#define CCPP_EXAM_CARDS_H

#include <stdio.h>
#include <string>


class cards {
public:
    // pure virtual function providing interface framework.
    virtual int whoAmI() = 0;
    void setSymbol(char s) {
        _symbol = s;
    }

    void setnumber(char n) {
        _number = n;
    }

protected:
    char _number;
    std::string _symbol;
};


#endif //CCPP_EXAM_CARDS_H
