//21BCE3188
//Compiler Design assignment 2 question 1
#include <iostream>
#include <fstream>
using namespace std;
int isNum(string str) {
  int flag = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      flag = 1;
    } else {
      flag = 0;
      break;
    }
  }
  return flag;
}
int isAlphaNum(char c) {
  int flag = 0;
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <=
      '9')) {
    flag = 1;
  }
  return flag;
}
string readFile(string filename) {
  string line;
  ifstream t;
  t.open(filename);
  string buffer = "";
  while (t) {
    getline(t, line);
    buffer += line;
  }
  t.close();
  return buffer;
}
string removeComment(string src) {
  string final1 = "";
  for (int i = 0; i < src.length(); i++) {
    if (src[i] == '/' && src[i + 1] == '*') {
      i += 2;
      while (src[i] != '*') {
        if (src[i + 1] == '*' && src[i + 2] == '/'){
          src[i] = ' ';
          i += 3;
          break;
        }
        i++;
      }
    }
    final1 += src[i];
  }
  return final1;
}
int main() {
  string keywords[] = {"if","int","then","print","else","endif"};
  string src = readFile("21BCE3188.txt");
  string tokens;
  src = removeComment(src);
  for (int i = 0; i < src.length(); i++) {
    if (isAlphaNum(src[i])) {
      while (isAlphaNum(src[i]))
        tokens += src[i++];
      i--;
      if (isNum(tokens))
        cout << tokens << " Constant\n";
      else {
        if (tokens.length() >= 60)
          cout << "identifier " << tokens << "is very long\nIdeal length is less than 60 \n ";
        cout << tokens << " Identifier\n";
      }
      tokens = "";
    }
  }
}