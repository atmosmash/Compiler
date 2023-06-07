//21BCE3188
//Compiler Design Assignment 2 question 3
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string readFile(string filename) {
  string line;
  fstream t;
  t.open(filename, std::ios::in);
  string buffer = "";
  while (t) {
    getline(t, line);
    buffer += line;
    line = "";
  }
  t.close();
  return buffer;
}
int comp_a(const string & input) {
  return input.length() == 1 && input == "a";
}
int comp_astarbplus(const string & input) {
  bool foundA = false;
  bool foundB = false;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 'a') {
      foundA = true;
      foundB = false;
    } else if (input[i] == 'b') {
      foundB = true;
    } else {
      return false;
    }
  }
  return foundB || (foundA && foundB);
}
int comp_abb(const string & input) {
  int currentstate = 0;
  for (int i = 0; i < input.length(); i++) {
    if (currentstate == 0 && input[i] == 'a')
      currentstate = 1;
    else if (currentstate == 1 && input[i] == 'b')
      currentstate = 2;
    else if (currentstate == 2 && input[i] == 'b')
      currentstate = 3;
    else
      currentstate = 4;
  }
  return currentstate == 3;
}
int main() {
  int output;
  string line;
  fstream t;
  t.open("21BCE3188_3.txt", std::ios::in);
  while (t) {
    getline(t, line);
    if (comp_astarbplus(line))
      cout << line << " is accepted by a*b+ \n";
    if (comp_abb(line))
      cout << line << " is accepted by abb \n";
    if (comp_a(line))
      cout << line << " is accepted by a \n";
    line = "";
  }
  t.close();
}