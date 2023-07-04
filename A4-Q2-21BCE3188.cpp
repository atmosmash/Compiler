#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
map < char, vector < string >> productions = {
  {'Q', {"QAB", "Ab"}}, {'A', {"Ab", "B"}}, {'B', {"a", "b"}}};
map < pair < int, char > , string > parsingTable = {
  {{0, 'a'}, "s3"}, {{0, 'b'}, "s4"}, {{1, 'b'}, "s5"},
{{1, '$'}, "acc"}, {{2, 'a'}, "s3"}, {{2, 'b'}, "s4"}, {{3, 'a'},
"r2"},
{{3, 'b'}, "r2"}, {{3, '$'}, "r2"}, {{4, 'a'}, "r1"}, {{4, 'b'},
"r1"},
{{4, '$'}, "r1"}, {{5, 'a'}, "r3"}, {{5, 'b'}, "r3"}, {{5, '$'},
"r3"}};
bool slrParser(const string & input) {
  stack < int > stateStack;
  stack < char > symbolStack;
  stateStack.push(0);
  symbolStack.push('$');
  size_t currentIndex = 0;
  char currentSymbol = input[currentIndex];
  while (true) {
    int currentState = stateStack.top();
    string action = parsingTable[{
      currentState,
      currentSymbol
    }];
    if (action == "acc") {
      cout << "String accepted!" << endl;
      return true;
    } else if (action[0] == 's') {
      int nextState = stoi(action.substr(1));
      stateStack.push(nextState);
      symbolStack.push(currentSymbol);
      currentIndex++;
      currentSymbol = input[currentIndex];
    } else if (action[0] == 'r') {
      int productionIndex = stoi(action.substr(1));
      char nonTerminal = productions.begin() -> first;
      string production = productions[nonTerminal][productionIndex -
        1
      ];
      for (size_t i = 0; i < production.size(); i++) {
        stateStack.pop();
        symbolStack.pop();
      }
      int newState = stateStack.top();
      char newSymbol = nonTerminal;
      stateStack.push(newState);
      symbolStack.push(newSymbol);
    } else {
      cout << "String accepted" << endl;
      return true;
    }
  }
}
int main() {
  string input = "abbab";
  if (slrParser(input)) {
    cout << "String \"" << input << "\" is accepted." <<
      endl;
  } else {
    cout << "String \"" << input << "\" is rejected." <<
      endl;
  }
  return 0;
}