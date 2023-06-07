//21BCE3188
//Compiler Design assignment 2 question 2
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string operators[] = {"=","+","-","*","/","^","&&",">=","!=","||","==","<=",">","<","++","--","+=","-=","*=","/="};
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
int isAlpabetNumber(string str) {
  int flag = 0;
  int decimal = 0;
  for (int i = 0; i < str.length(); i++) {
    if (isalnum(str[i])) {
      flag = 1;
    } else if (str[i] == '.') {
      decimal += 1;
      flag = 1;
      if (decimal > 1) {
        flag = 0;
      }
    } else {
      flag = 0;
      break;
    }
  }
  return flag;
}
int isOperator(string token) {
  int flag = 0;
  int length = sizeof(operators) / sizeof(operators[0]);
  for (int j = 0; j < length; j++) {
    if (token == operators[j]) {
      flag = 1;
      break;
    }
  }
  return flag;
}
int main() {
  string program = readFile("21BCE3188_Q2.txt");
  string lexeme;
  string final1;
  for (int i = 0; i < program.length(); i++) {
    if (program[i] == '/' && program[i + 1] == '*') {
      i += 2;
      while (program[i] != '*') {
        if (program[i + 1] == '*' && program[i + 2] == '/')
          {
            program[i] = ' ';
            i += 3;
            break;
          }
        i++;
      }
    }
    final1 += program[i];
  }
  program = final1;
  for (int i = 0; i < program.length(); i++) {
    if (program[i] != ' ' && !isalnum(program[i])) {
      while (program[i] != ' ' && !isalnum(program[i]))
        lexeme += program[i++];
      i--;
      if (isOperator(lexeme)) {
        cout << lexeme << " is valid operator\n";
      } else {
        cout << lexeme << " is invalid operator\n";
      }
      lexeme = "";
    }
  }
}