// operator identify
#include<stdio.h>
#include<string.h>
int main(){
    char str[20];
    //taking string input
    printf("Enter string : ");
    gets(str);
    printf("The string you entered is: %s", str);
    int len = strlen(str);
    //checking if the entered string has operators
    for(int i=0;i<len;i++){
        if (str[i]=="*"||str[i]=="+"||str[i]=="/"||str[i]=="-"){
            printf("Operator entered at index %i\n", i);
            printf("Entered operator: %c", str[i]);
        }
        else{
            printf("Operator not entered at index %d\n",i);
        }
    }
    return 0;
}