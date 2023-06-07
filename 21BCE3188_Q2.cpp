#include<stdio.h>
#include<conio.h>
void main()
{
    char str[30];
    int i = 2, a = 0;
    clrscr();
    printf("\n\nEnter string : ");
    gets(str);
    if(str[0] == '/')
    {
        if(str[1] == '/') {
            printf("\nIt is a Comment.");
        } 
        else if(str[1] == '*') 
        {
            for(i = 2; i <= 30; i++)
            {
                if(str[i] == '*' && str[i + 1] == '/')
                {
                    printf("\nIt is a Comment.");
                    a = 1;
                    break;
                }
                else {
                    continue;
                }
            }
            if(a == 0)
            {
                printf("\nIt is Not a Comment.");
            }
            else
            {
                printf("\nIt is Not a Comment.");
            }
        }
    }
    else
    {
        printf("\nIt is Not a Comment.");
    }
    getch();
}
        
      