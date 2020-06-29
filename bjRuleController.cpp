#include "bjRuleController.h"
#include <fstream>
#include <iostream>

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

bjRuleController *bjRuleController::getInstance() {
    if (instance == nullptr) {
        instance = new bjRuleController();
    }

    return instance;
}


int bjRuleController::getDealerMaxPoints() const {
    return dealerMaxPoints;
}



int bjRuleController::getReshuffelTrigger() const {
    return reshuffelTrigger;
}

void bjRuleController::setReshuffelTrigger(int reshuffelTrigger) {
    reshuffelTrigger = reshuffelTrigger;
}

int bjRuleController::getNumberOfDecks() const {
    return numberOfDecks;
}

void bjRuleController::setNumberOfDecks(int numberOfDecks) {
    numberOfDecks = numberOfDecks;
}

int bjRuleController::getInitChips() const {
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
}

int bjRuleController::oneEleven() {
    int in;
    while (in != 1 && in != 11) {
        printf("You have drawn an Ace. You can decide if it has the value 1 or 11\n");
        printf("Which Value has your Ace: ");
        std::cin >> in;
    }
    return in;
}

