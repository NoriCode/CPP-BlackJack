#CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++14"
#Topic 2: Toolchain: getrennte Übersetzung
gcc -c main.cpp
gcc -c bjCards.cpp
gcc -c bjDeck.cpp
gcc -c bjHand.cpp
gcc -c bjPlayer.cpp
gcc -c bjRuleController.cpp
gcc -c blackJack.cpp

#Topic 3: Toolchain: Fehler und Warnings
g++ -Wall -Wextra -Werror -Wmissing-prototypes -g main.o bjCards.o bjDeck.o bjHand.o bjPlayer.o bjRuleController.o blackJack.o -o blackJack.out
