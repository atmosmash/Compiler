// c program to accept strings a, a*b+, abb
#include<stdio.h>
#include<stdlib.h>
void main(){
    char s[20],c;
    int state=0,i=0;
    printf("\n Enter a string:");
    gets(s);
    while(s[i]!='\0'){
        switch(state){
            case 0: 
            c=s[i++];
            if(c=='a'){
                state=1;
            }
            else if(c=='b'){
                state=5;
            }
            else{
                state=6;
            break;
            }
            case 1: 
            c=s[i++];
            if(c=='a') {
                state=2;
            }
            
            else if (c=='b') {
                state=3;
            }
            else{
            state=6; 
            break;
            }
            case 2: 
            c=s[i++];
            if(c=='a'){
            state=2;
            }
            else if(c=='b'){
            state=5;
            }
            else {
            state=6; 
            break;
            }
            case 3: 
            c=s[i++];
            if (c=='b'){ 
            state=4;
            }
            else{
                state=6;
                break;
            }
            case 4: 
            c=s[i++];
            if (c=='b'){
            state=5;
            }
            else{
            state=6;
            break;
            }
            case 5: 
            c=s[i++];
            if (c=='b'){
            state=5;
            }
            else{
            state=6;
            break;
            }
            case 6: 
            printf("\n %s is not recognised.",s);
            exit(0);
        }
    }
}   