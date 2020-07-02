
#include "blackJack.h"
#include "bjRuleController.h"
#include <cstdio>

int main() {


    bjRuleController *bjR = new bjRuleController();
    blackJack *bJ;

    bJ->getInstance()->game();

    return 0;
}