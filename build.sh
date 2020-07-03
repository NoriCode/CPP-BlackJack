#CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++14"
gcc -c main.cpp
gcc -c bjCards.cpp
gcc -c bjDeck.cpp
gcc -c bjHand.cpp
gcc -c bjPlayer.cpp
gcc -c bjRuleController.cpp
gcc -c blackJack.cpp
# gcc -o test  blackJack main.o bjCards.o bjDeck.o bjHand.o bjPlayer.o bjRuleController.o blackJack.o
g++ -Wall -g main.o bjCards.o bjDeck.o bjHand.o bjPlayer.o bjRuleController.o blackJack.o -o test
