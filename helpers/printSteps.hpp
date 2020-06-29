
#ifndef printSteps_hpp
#define printSteps_hpp

#include <string>
#include <vector>
#include "AnsiConsole.hpp"

struct printCmd {
    int line;
    std::string func;
    int stepNum;
    int colOffset;
};

extern int stepNum;
extern int colorOffset;
extern bool printSource;
extern std::vector<printCmd> commands;

void printCommands(std::string fileName);

void resetCommands();

// NOP stand for "no operation"; it does log the step and line number though
//#define NOP commands.push_back({__LINE__, __func__});
#define nop commands.push_back({__LINE__, __func__, ++stepNum, colorOffset});
#define TITLE(label) {ansiConsole.clearScreen();commands.push_back({0, label,0,0});}


#endif /* printSteps_hpp */
