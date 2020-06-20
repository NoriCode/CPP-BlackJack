#include <stdio.h>
#include "playCardDeck.h"
#include "bjRuleController.h"

int menu(int in) {
    printf("Welcome to Blackjack\n");
    printf("Your options are:\n");
    printf("1 - Play\n");
    printf("2 - Rules\n");
    printf("3 - Exit\n");
    std::cin >> in;
    return in;
}

int game() {
    playCardDeck p;
    p.generatePlayDeck();
    p.resetPlayDeck();
    return 0;
}

int main() {
    int menuOption = 0;
    while (menuOption != 3) {
        menuOption = menu(menuOption);
        if (menuOption == 1) {
            game();
            menuOption=3;
        } else if (menuOption == 2) {
            bjRuleController::printRules();
        }
    }
    return 0;
}
