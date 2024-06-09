/**
 * Using stacks to reverse a list
*/
#include <stdio.h>
#include <stdlib.h>

int pop(int *Stack,int *top)
{
    if (*top==-1)
    {
        return 0;
    }else
    {
        return (Stack[(*top)--]);
    }
    
}
int push(int *Stack, int *top, int topush,int size)
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
void reverse(int *Stack, int *top, int *arr, int index)
{
    if (*top==-1)
    {
        return;
    }else
    {
        int temp;
        temp=pop(Stack,top); 
        if (temp!=0)
        {
            arr[index]=temp;
            reverse(Stack,top,arr,index+1); 
        }
    }

}

int main(void)
{
    //declarations
    int arr[]={1,3,300,221};
    int *Stack= (int*)calloc(4,sizeof(int));
    int top=-1;
    //  Display original array
    for (int i = 0; i < 4; i++)
    {
        printf("\n%d",arr[i]);
        push(Stack,&top,arr[i],5);
    }
    reverse(Stack,&top,arr,0);
    printf("\n--------------------------");
    //  Display reversed array
    for (int i = 0; i < 4; i++)
    {
        printf("\n%d",arr[i]);
    }
    
}