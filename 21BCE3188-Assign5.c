#include <stdio.h>
#include <stdlib.h>
int readFile(char * buffer) {
  FILE * file = fopen("21BCE3188.txt", "r");
  fgets(buffer, 200, file);
  return 0;
}
int calcExpr(char * expression) {
  int result = 0;
  int digit = 0;
  int operator = '+';
  while ( * expression) {
    if ( * expression >= '0' && * expression <= '9') {
      digit = digit * 10 + ( * expression - '0');
    } else if ( * expression == '+' || * expression == '*') {
      printf("Operator: %c\n", * expression);
      printf("Current Result: %d\n", result);
      printf("Current Digit: %d\n", digit);
      printf("Current Operator: %c\n\n", operator);
      if (operator == '+') {
        result += digit;
      } else if (operator == '*') {
        result *= digit;
      }
      digit = 0;
      operator = * expression;
    }
    expression++;
  }
  printf("Operator: %c\n", * expression);
  printf("Current Result: %d\n", result);
  printf("Current Digit: %d\n", digit);
  printf("Current Operator: %c\n\n", operator);
  if (operator == '+') {
    result += digit;
  } else if (operator == '*') {
    result *= digit;
  }
  return result;
}
int main() {
  char expression[200];
  readFile(expression);
  int result = calcExpr(expression);
  printf("Result: %d\n", result);
  return 0;
}