
#include "AnsiConsole.h"

/*
 see
 https://en.wikipedia.org/wiki/ANSI_escape_code
 https://gist.github.com/vratiu/9780109
 https://gist.github.com/RobinMalfait/7881398
 */

AnsiConsole ansiConsole;


AnsiConsole::AnsiConsole() : maxY(1) {
  //pushCursorPos();
  //hideCursor();
  //clearScreen();
}

AnsiConsole::~AnsiConsole(){
  //popCursorPos();
  std::cout << "\033[0m\n"; // reset attributes
  std::cout << "\033[" << maxY+1 << ";" << 1 <<  "f"; // move cursor
  showCursor();
}


void AnsiConsole::hideCursor(){
  std::cout << "\033[?25l";
}

void AnsiConsole::showCursor(){
  std::cout << "\033[?25h";
}

void AnsiConsole::pushCursorPos(){
  std::cout << "\033[s";
}

void AnsiConsole::popCursorPos(){
    std::cout << "\033[u";
}



void AnsiConsole::clearScreen(){
//  std::cout << "\033[0J";
    std::cout << "\033[2J";
}

void AnsiConsole::printText(int x, int y, std::string text){
  printText(x,y,text, Colors::NONE);
}


void AnsiConsole::printText(int x, int y, std::string text, Colors color, bool bold){
  maxY = std::max(y,maxY);
  std::cout << "\033[" << y << ";" << x <<  "f"; // move cursor to x,y
  if(color != Colors::NONE){
    std::cout << (bold ? "\033[1;" : "\033[0;")
    << static_cast<int>(color) << "m"; // Color
  }
  std::cout << text ;//<< "-" << std::to_string(maxY);
  std::cout << "\033[0m"; // reset attributes \n ?
}



