/**
 * Design the recursive function to push a whole string on a stack
*/
#include <stdio.h>

int push(char *Stack, int *top, int size, char topush)
{
    if (*top==size-1)
    {
        return 0;
    }else
    {
        Stack[++(*top)]=topush;
        return 1;
    }    
    
}

void push_str(char *Stack, char *arr, int *top, int size)
{
    if (arr[0]=='\0')
    {
        return;
    }else
    {
        push(Stack,top,size,arr[0]);
        push_str(Stack,arr+1,top,size);
    }   
}