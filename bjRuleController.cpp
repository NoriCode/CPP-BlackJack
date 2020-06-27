#include "bjRuleController.h"
#include <fstream>
#include <iostream>

bjRuleController *bjRuleController::instance = 0;

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
    if (instance == 0) {
        instance = new bjRuleController();
    }

    return instance;
}

bjRuleController::bjRuleController() {}

int bjRuleController::getDealerMaxPoints() const {
    return _dealerMaxPoints;
}

void bjRuleController::setDealerMaxPoints(int dealerMaxPoints) {
    _dealerMaxPoints = dealerMaxPoints;
}

int bjRuleController::getBlackjack() const {
    return _blackjack;
}

void bjRuleController::setBlackjack(int blackjack) {
    _blackjack = blackjack;
}

double bjRuleController::getReturnValue() const {
    return _returnValue;
}

void bjRuleController::setReturnValue(double returnValue) {
    _returnValue = returnValue;
}

int bjRuleController::getPlayerBet() const {
    return _playerBet;
}

void bjRuleController::setPlayerBet(int playerBet) {
    _playerBet = playerBet;
}

int bjRuleController::getReshuffelTrigger() const {
    return _reshuffelTrigger;
}

void bjRuleController::setReshuffelTrigger(int reshuffelTrigger) {
    _reshuffelTrigger = reshuffelTrigger;
}

int bjRuleController::getNumberOfDecks() const {
    return _numberOfDecks;
}

void bjRuleController::setNumberOfDecks(int numberOfDecks) {
    _numberOfDecks = numberOfDecks;
}

int bjRuleController::getInitChips() {
    return _initChips;
}

int bjRuleController::getMinBet() {
    return minBet;
}

int bjRuleController::getMaxBet() {
    return maxBet;
}

