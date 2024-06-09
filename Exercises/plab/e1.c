/**
 * Write a program in C to read n number of values in an array and display it in reverse
order.
*/
#include <stdio.h> 
#define SIZE 5

int main(void)
{
    //declarations
    int arr[SIZE],rev[SIZE],i;
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of the %d element> ",i+1);
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < SIZE; i++)
    {
        rev[i]=arr[SIZE-(i+1)];
    }
    printf("\nReverse: ");
    for ( i = 0; i < SIZE; i++)
    {
        printf("\n%d",rev[i]);
    }
    return 0;
    
}