#include <stdio.h>
#include "helpers/println.hpp"

int menu(int in){
    printf("Welcome to Blackjack\n");
    printf("Your options are:\n");
    printf("1 - Play\n");
    printf("2 - Rules\n");
    printf("3 - Exit\n");
    std::cin >> in;
    return in;
}

int main() {
    int menuOption = 0;
    while(menuOption != 3){
        menuOption = menu(menuOption);
    }
    return 0;
}
