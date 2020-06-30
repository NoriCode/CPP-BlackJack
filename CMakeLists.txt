cmake_minimum_required(VERSION 3.16)
project(CCPP_Exam)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(CCPP_Exam main.cpp
        bjRuleController.cpp
        bjCards.cpp

        bjHand.cpp

        blackJack.cpp

        tempDeck.cpp

        tempPlayer.cpp
        bjDealer.cpp bjDealer.h)


#set_target_properties(CCPP_Exam PROPERTIES SUFFIX ".out")