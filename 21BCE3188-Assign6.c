#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct ast_node {
  char label;
  int value;
  struct ast_node * left;
  struct ast_node * right;
}
ASTNode;
ASTNode * createNode(char label, int value) {
  ASTNode * node = (ASTNode * ) malloc(sizeof(ASTNode));
  node -> label = label;
  node -> value = value;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
ASTNode * parseExpression();
char * input;
int position;
char peek() {
  return input[position];
}
void advance() {
  position++;
}
ASTNode * parseFactor() {
  ASTNode * node = NULL;
  if (isdigit(peek())) {
    int value = peek() - '0';
    advance();
    node = createNode('D', value);
  } else if (peek() == '(') {
    advance(); // consume '('
    node = parseExpression();
    if (peek() != ')') {
      printf("Error: Expected ')'\n");
      exit(1);
    }
    advance();
  } else {
    printf("Error: Invalid expression\n");
    exit(1);
  }
  return node;
}
ASTNode * parseTerm() {
  ASTNode * left = parseFactor();
  while (peek() == '*' || peek() == '/') {
    char op = peek();
    advance();
    ASTNode * right = parseFactor();
    ASTNode * node = createNode(op, 0);
    node -> left = left;
    node -> right = right;
    left = node;
  }
  return left;
}
ASTNode * parseExpression() {
  ASTNode * left = parseTerm();
  while (peek() == '+' || peek() == '-') {
    char op = peek();
    advance();
    ASTNode * right = parseTerm();
    ASTNode * node = createNode(op, 0);
    node -> left = left;
    node -> right = right;
    left = node;
  }
  return left;
}
void printAST(ASTNode * node, int indent) {
  if (node == NULL)
    return;
  for (int i = 0; i < indent; i++) {
    if (i == 0)
      printf("|");
    if (i < indent - 1)
      printf(" ");
    else
      printf("\\-");
  }
  printf("%c", node -> label);
  if (node -> label == 'D')
    printf("(%d)", node -> value);
  printf("\n");
  printAST(node -> left, indent + 2);
  printAST(node -> right, indent + 2);
}
void generateThreeAddressCode(ASTNode * node) {
  if (node == NULL)
    return;
  if (node -> label == '+' || node -> label == '-' || node -> label == '*' ||
    node -> label == '/') {
    printf("%c := ", node -> label);
    if (node -> left -> label == 'D')
      printf("%d", node -> left -> value);
    else
      printf("t%d", node -> left -> value);
    printf(" %c ", node -> label);
    if (node -> right -> label == 'D')
      printf("%d", node -> right -> value);
    else
      printf("t%d", node -> right -> value);
    printf("\n");
    node -> value = node -> left -> value;
    node -> left -> value = node -> right -> value;
    node -> right -> value = node -> value + 1;
  }
  generateThreeAddressCode(node -> left);
  generateThreeAddressCode(node -> right);
}
int main() {
      printf("Enter an expression: "); input = (char * ) malloc(256); scanf("%[^\n]", input); ASTNode * root = parseExpression(); printf("Abstract Syntax Tree:\n"); printAST(root, 0); printf("\nThree Address Code:\n"); generateThreeAddressCode(root); free(input);
      return 0;
    }