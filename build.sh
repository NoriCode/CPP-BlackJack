#!/bin/bash
CPP_SRC_UTIL_PATH=${CPP_SRC_UTIL_PATH:-.}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++14"

clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out main.cpp
clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out bjCards.cpp
clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out bjDealer.cpp
clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out bjDeck.cpp
clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out bjHand.cpp
# shellcheck disable=SC2086
# shellcheck disable=SC2086
clang++ "${CPPFLAGS}" -I${CPP_SRC_UTIL_PATH} -o CCPP_Exam.out bjPlayer.cpp
# shellcheck disable=SC2086
clang++ "${CPPFLAGS}" -I${CPP_SRC_UTIL_PATH} -o CCPP_Exam.out bjRuleController.cpp
clang++ "${CPPFLAGS}" -I"${CPP_SRC_UTIL_PATH}" -o CCPP_Exam.out blackJack.cpp
