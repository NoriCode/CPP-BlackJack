#include "cards.h"
class bjCards: public cards {
protected:
    int value;
public:
    // pure virtual function providing interface framework.
    virtual int whoAmI() = 0;
    void setSymbol(char s) {
        symbol = s;
    }

    void setnumber(char n) {
        number = n;
    }
    void setValue(int v){
        value =v;
    }
    int getValue(){
        return value;
    }
};