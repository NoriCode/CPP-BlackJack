//
// Created by nori on 06.07.20.
//

#ifndef CCPP_EXAM_ENUMS_H
#define CCPP_EXAM_ENUMS_H
enum playerOption {
    HIT = 1, STAND
};

enum gameState {
    NEWGAME = 1, LEAVE, PLAYING
};

enum mainMenu {
    PLAY = 1, RULES, EXIT
};

enum playerStatus {
    VICTORY = 0,
    TIE,
    LOSS
};

#endif //CCPP_EXAM_ENUMS_H
