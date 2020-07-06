#ifndef CCPP_EXAM_PLAYINGCARD_H
#define CCPP_EXAM_PLAYINGCARD_H


#include <string>

class playingCard {
private:
    std::string symbol;
    std::string number;

public:
    //Topic 26: Häufige fehlerquellen -> keine Uninitialisierten variablen
    explicit playingCard(std::string s = "nori", std::string n = "0") : symbol(std::move(s)), number(std::move(n)) {}

    //Topic 15: Object Orientation: subtyping polymorhism / virtual methods
    //Topic 19: späte Bindung von Methoden und Funktionen
    virtual void whoAmI() = 0;

    //Topic 18: frühe Bindung von Methoden und Funktionen
    std::string getNumber() {
        return number;
    };

    //Topic 18: frühe Bindung von Methoden und Funktionen
    std::string getSymbol() {
        return symbol;
    };

};

#endif //CCPP_EXAM_PLAYINGCARD_H
