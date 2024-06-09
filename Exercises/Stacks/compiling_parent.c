/**
 * Write a function to check wether the parenthesis in an expression are balanced
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 7
int push(char *Stack,int *top, char topush)
{
    if (*top==SIZE-1)
    {
        return 0;
    }else
    {
        Stack[++(*top)]=topush;
        return 1;
    }
}
char pop(char *Stack, int *top)
{
    if (*top==-1)
    {
        return '*';
    }else
    {
        return (Stack[(*top)--]);
    }
}

int check_par(char *Stack,char *str,int *top)
{
    if (str[0]=='\0')
    {
        if (*top==-1)
        {
            return 1;
        }else
        {
            return 0;
        }
    }else
    {
        if (str[0]=='(' ||str[0]=='[')
        {
            push(Stack,top,str[0]);
        }else if (str[0]==')'||str[0]==']')
        {
            char popped=pop(Stack,top);
            if ((str[0]==')'&& popped!='(') ||(str[0]==']'&& popped!='['))
            {
                return 0;
            }   
        }
    } 
}

int main(void)
{
    //declarations
    char expression[]="[(A+B)*C";
    char *Stack=(char*)calloc(strlen(expression),sizeof(char));
    int top=-1;

    if (check_par(Stack,expression,&top))
    {
        printf("\nExpression %s is balanced",expression);
    }else
    {
        printf("\nExpression %s is not balanced",expression);
    }
    return 0;
}