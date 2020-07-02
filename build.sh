#!/bin/bash
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++14"
 gcc -c test bjCards.cpp
 gcc -c test bjDeck.cpp
 gcc -c test  bjHand.cpp
 gcc -c  test bjPlayer.cpp
 gcc -c  test bjRuleController.cpp
 gcc -c  test blackJack.cpp
# gcc -o test  blackJack main.o bjCards.o bjDeck.o bjHand.o bjPlayer.o bjRuleController.o blackJack.o
 gcc -Wall -g bjCards.o bjDeck.o bjHand.o bjPlayer.o bjRuleController.o blackJack.o -o main.cpp
