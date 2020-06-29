cmake_minimum_required(VERSION 3.16)
project(CCPP_Exam)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(CCPP_Exam main.cpp
        cards.cpp
        playCardDeck.cpp
        bjRuleController.cpp
        bjCards.cpp
        bjCards.h
        bjplayer.cpp
        bjplayer.h
        deck.cpp
        deck.h
        playerdeck.cpp
        playerdeck.h
        player.cpp
        player.h
        bjNonPlayer.cpp
        bjNonPlayer.h bjHand.cpp bjHand.h blackJack.cpp blackJack.h)


#set_target_properties(CCPP_Exam PROPERTIES SUFFIX ".out")