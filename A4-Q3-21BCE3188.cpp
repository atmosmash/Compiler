#include <iostream>
#include <map>
#include <vector>
std::map < char, std::vector < std::string >> productions = {
{'E', {"E+T", "T"}}, {'T', {"T*F", "F"}}, {'F', {"(E)", "i"}}};
std::map<std::pair<int, char>, std::string> parsingTable = {
{{0, 'i'}, "s5"}, {{0, '('}, "s4"}, {{1, '+'}, "s6"}, {{1, '*'},
"s7"},
{{1, ')'}, "r2"}, {{1, '$'}, "acc"}, {{2, '+'}, "r1"}, {{2, '*'},
"s7"},
{{2, ')'}, "r1"}, {{3, '+'}, "r4"}, {{3, '*'}, "r4"}, {{3, ')'},
"r4"},
{{4, 'i'}, "s5"}, {{4, '('}, "s4"}, {{5, '+'}, "r6"}, {{5, '*'},
"r6"},
{{5, ')'}, "r6"}, {{6, 'i'}, "s5"}, {{6, '('}, "s4"}, {{7, 'i'},
"s5"},
{{7, '('}, "s4"}, {{8, '+'}, "s6"}, {{8, ')'}, "s11"}, {{9, '+'},
"r3"},
{{9, '*'}, "s7"}, {{9, ')'}, "r3"}, {{10, '+'}, "r5"}, {{10, '*'},
"r5"},
{{10, ')'}, "r5"}, {{11, '+'}, "r7"}, {{11, '*'}, "r7"}, {{11, ')'},
"r7"},
{{0, 'E'}, "1"}, {{1, 'E'}, "8"}, {{1, 'T'}, "2"}, {{2, 'T'}, "3"},
{{2, 'F'}, "8"}, {{3, 'F'}, "9"}, {{4, 'T'}, "10"}, {{5, 'F'},
"11"},
{{6, 'F'}, "12"}, {{7, 'T'}, "13"}, {{8, 'E'}, "14"}, {{9, 'E'},
"15"},
{{9, 'T'}, "2"}, {{10, 'T'}, "16"}, {{10, 'F'}, "8"}, {{11, 'F'},
"17"}};
void clrParser(const std::string & input) {
  std::vector < int > stateStack;
  std::vector < char > symbolStack;
  stateStack.push_back(0);
  symbolStack.push_back('$');
  size_t currentIndex = 0;
  char currentSymbol = input[currentIndex];
  while (true) {
    int currentState = stateStack.back();
    std::string action = parsingTable[{
      currentState,
      currentSymbol
    }];
    std::cout << "Current State Stack: ";
    for (const auto & state: stateStack) {
      std::cout << state << " ";
    }
    std::cout << "\n";
    std::cout << "Current Symbol Stack: ";
    for (const auto & symbol: symbolStack) {
      std::cout << symbol << " ";
    }
    std::cout << "\n";
    std::cout << "Input: " << input.substr(currentIndex) << "\n";
    if (action == "acc") {
      std::cout << "String accepted!\n";
      break;
    } else if (action[0] == 's') {
      int nextState = stoi(action.substr(1));
      stateStack.push_back(nextState);
      symbolStack.push_back(currentSymbol);
      currentIndex++;
      if (currentIndex < input.size()) {
        currentSymbol = input[currentIndex];
      }
    } else if (action[0] == 'r') {
      int productionIndex = stoi(action.substr(1));
      char nonTerminal = productions.begin() -> first;
      const std::vector < std::string > & production =
        productions[nonTerminal];
      const std::string & selectedProduction = production[productionIndex -
        1];
      std::cout << "Applying Production: " << nonTerminal << " -> " <<
        selectedProduction << "\n";
      for (size_t i = 0; i < selectedProduction.size() * 2; i++) {
        stateStack.pop_back();
        symbolStack.pop_back();
      }
      int newState = stateStack.back();
      char newSymbol = nonTerminal;
      stateStack.push_back(newState);
      symbolStack.push_back(newSymbol);
      int nextState = stoi(parsingTable[{
        newState,
        newSymbol
      }]);
      stateStack.push_back(nextState);
    } else {
      std::cout << "String rejected!\n";
      break;
    }
  }
}
int main() {
  std::string input = "(i*i)+(i*i)+i";
  clrParser(input);
  return 0;
}