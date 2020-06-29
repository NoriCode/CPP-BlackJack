#include "blackJack.h"
#include "bjRuleController.h"

int main() {
    blackJack *bJ;

    bjRuleController * bjr = bjRuleController::getInstance();

    bJ = new blackJack(bjr);

    bJ->game();
    return 0;
}
