#include "printSteps.hpp"
#include "AnsiConsole.hpp"
#include <fstream>
#include <sstream>
#include <thread>


int stepNum = 0;
int colorOffset = 0;
std::vector<printCmd> commands;
//AnsiConsole console;
int xspace=8;
int sleepTime = 0;
bool useColor = false;
bool printSource = true;

void resetCommands(){
  commands.clear();
  stepNum = 0;
}

bool endsWith(const std::string& s, const std::string& suffix)
{
  return s.size() >= suffix.size() &&
  s.substr(s.size() - suffix.size()) == suffix;
}

// see https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string& s, const std::string& delimiter, const bool& removeEmptyEntries = false)
{
  std::vector<std::string> tokens;
  
  for (size_t start = 0, end; start < s.length(); start = end + delimiter.length())
  {
    size_t position = s.find(delimiter, start);
    end = position != std::string::npos ? position : s.length();
    
    std::string token = s.substr(start, end - start);
    if (!removeEmptyEntries || !token.empty())
    {
      tokens.push_back(token);
    }
  }
  
  if (!removeEmptyEntries &&
      (s.empty() || endsWith(s, delimiter)))
  {
    tokens.push_back("");
  }
  
  return tokens;
}

std::string lineFromFile(std::string fileName, int lineNum){
  std::string result = "";
  
  std::ifstream inFile;
  inFile.open(fileName); //open the input file
  
  std::stringstream strStream;
  strStream << inFile.rdbuf(); //read the file
  std::string str = strStream.str(); //str holds the content of the file
  
  result = split(str,std::string("\n"))[lineNum];
  
  return result;
}

void printCommands(std::string fileName){
  int lowestLine = 1000;
  int highestLine = 0;
  for(unsigned int i=0; i<commands.size();i++){
    if((commands[i].line>0) && (commands[i].line < lowestLine)){
      lowestLine = commands[i].line;
    }
    if(commands[i].line > highestLine){
      highestLine = commands[i].line;
    }
  }
  lowestLine--;
  highestLine++;
  //println("lowestLine=", lowestLine, " highestLine=", highestLine);
  
  // print line numbers
  for(int j=lowestLine; j<=highestLine;j++){
    ansiConsole.printText(1, 2+j-lowestLine,
                      std::to_string(j) + " ", useColor ? Colors::RED : Colors::BLACK, true);
  }
  
  // print source lines
  if (printSource){
    for(int j=lowestLine; j<=highestLine;j++){
      ansiConsole.printText(5, 2+j-lowestLine,
                        lineFromFile(fileName, j-1), useColor ? Colors::GREEN : Colors::WHITE);
    }
  }
  
  if(sleepTime > 0){
    std::cout << std::flush;
  }
  // print step numbers
  if (!printSource) {
    xspace = 5;
  }
  //int highestY = 1;
  for(unsigned int i=0; i<commands.size();i++){
    if(commands[i].line>0){
      //std::string lineNumberStr = std::to_string(commands[i].line);
      std::string lineNumberStr =  std::to_string(commands[i].stepNum);
      int y = 2+commands[i].line-lowestLine;
      Colors colorToUse = (useColor || commands[i].colOffset>0) ? static_cast<Colors>(static_cast<int>(Colors::RED) + commands[i].colOffset) : Colors::NONE;
      ansiConsole.printText(1+i*2+xspace, y, lineNumberStr, colorToUse, true);
      //if(y>highestY) highestY = y;
    }else{
      //colOffset
      Colors colorToUse = (useColor ? Colors::BLUE : Colors::NONE);
      ansiConsole.printText(1, 1, commands[i].func, colorToUse);
    }
    if(sleepTime > 0){
      std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
      std::cout << std::flush;
    }
  }
  //ansiConsole.printText(1, highestY+1, "done.", useColor ? Colors::BLUE : Colors::NONE);
}

