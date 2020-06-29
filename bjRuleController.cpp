#include "bjRuleController.h"
#include <fstream>
#include <iostream>
/*
bjRuleController* bjRuleController::instance = 0;

bjRuleController* bjRuleController::getInstance()  {
    if (instance == 0)
    {
        instance = new bjRuleController();
    }

    return instance;
}

bjRuleController::bjRuleController() = default;
*/
void bjRuleController::printRules() {
    std::string line;
    std::ifstream file;
    file.open("bjRules.txt");

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
}

/*
bjRuleController *bjRuleController::getInstance() {
    if (instance) {
        instance = new bjRuleController();
    }

    return instance;
}*/
/*

int bjRuleController::getDealerMaxPoints()  {
    return dealerMaxPoints;
}



int bjRuleController::getReshuffelTrigger()  {
    return reshuffelTrigger;
}


int bjRuleController::getNumberOfDecks() {
    return numberOfDecks;
}

/*
int bjRuleController::getInitChips() {
    return initChips;
}

int bjRuleController::getMinBet() {
    return minBet;
}

int bjRuleController::getMaxBet() {
    return maxBet;
}

void bjRuleController::playerWin() {
    printf("\n You have won your bet is multiplied by 1.5\n");
}

void bjRuleController::playerLoose() {
    printf("\n You have lost.\n");
}

void bjRuleController::playerTie() {
    printf("\n Tie. You get your bet back\n");
}*/

bjRuleController::bjRuleController() {

}


int bjRuleController::getDealerMaxPoints() const {
    return dealerMaxPoints;
}

int bjRuleController::getReshuffelTrigger() const {
    return reshuffelTrigger;
}

int bjRuleController::getNumberOfDecks() const {
    return numberOfDecks;r
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
