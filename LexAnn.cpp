//Lexical Analyser
#include<iostream>
#include<fstream>/*The fstream term stands for File Stream. Stream refers to a sequence of characters moving from the disk to the C++ program or from the C+ program to the disk. Moving characters from a file in disk to the program is inputting. Moving characters from the program to a file in the disk is outputting.*/
#include<string.h>
#include<stdlib.h>
bool isPun(char ch){
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
        ch == '&' || ch == '|')
        {
            return true;
        }
    return false;
}
bool id(char *str){
    
}