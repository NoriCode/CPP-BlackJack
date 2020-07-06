//Topic 13:  Object Orientation: Inheritance
#include "bjRuleController.h"
#include <fstream>

void bjRuleController::printRules() {
    std::string line;
    std::ifstream file;
    file.open("bjRules.txt");

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (file.is_open()) {
        //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
    printf("\n\n\n");
}

void bjRuleController::playerWin() {
    printf("\n\n\n\n******************************************\n");
    printf("You have won your bet is multiplied by 2\n");
}

void bjRuleController::playerLoose() {
    printf("\n\n\n\n******************************************\n");
    printf("You lost.\n");
}

void bjRuleController::playerTie() {
    printf("\n\n\n\n******************************************\n");
    printf("Tie. You get your bet back\n");
}

bjRuleController::bjRuleController() {
    dealerMaxPoints = 17;
    reshuffelTrigger = 75;
    numberOfDecks = 6;
    initChips = 1000;
    minBet = 2;
    maxBet = 500;
}


int bjRuleController::getDealerMaxPoints() const {
    return dealerMaxPoints;
}

int bjRuleController::getReshuffelTrigger() const {
    return reshuffelTrigger;
}

int bjRuleController::getNumberOfDecks() const {
    return numberOfDecks;
}

int bjRuleController::getInitChips() const {
    return initChips;
}

int bjRuleController::getMinBet() const {
    return minBet;
}

int bjRuleController::getMaxBet() const {
    return maxBet;
}

  playerStatus bjRuleController::winLossTieControll(int pValue, int dValue) {

    //Topic 9: Kontrollfluß: grundlegende Kontrollstrukturen
    if (pValue > 21) {
        playerLoose();
        return LOSS;
    } else if (pValue == 21) {
        if (dValue == 21) {
            playerTie();
            return TIE;
        }
    } else {
        if (dValue <= 21) {
            if (pValue < dValue) {
                playerLoose();
                return LOSS;
            } else if (pValue == dValue) {
                playerTie();
                return TIE;
            }
        }
    }
    playerWin();
    return VICTORY;
}

