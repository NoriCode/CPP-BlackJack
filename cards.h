#ifndef CCPP_EXAM_CARDS_H
#define CCPP_EXAM_CARDS_H


class cards {
public:
    // pure virtual function providing interface framework.
    virtual int whoAmI() = 0;
    void setSymbol(char s) {
        symbol = s;
    }

    void setnumber(char n) {
        number = n;
    }

protected:
    char number;
    char symbol;
};


#endif //CCPP_EXAM_CARDS_H
