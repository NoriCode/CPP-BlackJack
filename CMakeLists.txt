cmake_minimum_required(VERSION 3.16)
project(CCPP_Exam)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")

add_executable(CCPP_Exam main.cpp cards.cpp playCardDeck.cpp bjRuleController.cpp test.txt bjCards.cpp bjCards.h myLittlehelpers.cpp myLittlehelpers.h player.cpp player.h deck.cpp deck.h playerdeck.cpp playerdeck.h)