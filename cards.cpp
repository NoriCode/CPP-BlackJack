#include "cards.h"

class bjCards : public cards {
protected:
    int value;
public:
    void setValue(int v) {
        value = v;
    }

    int getValue() {
        return value;
    }
};