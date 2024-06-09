/**
 * 2. Write a program in C to find the maximum and minimum element in an array
*/
#include <stdio.h>
#define SIZE 5
int main(void)
{
    //declarations
    int arr[SIZE],max,min,i;
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of the %d element of the array> ",i+1);
        scanf("%d",&arr[i]);
    }
    //check min
    min=arr[0];
    for ( i = 1; i < SIZE; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
        
    }
    //find max
    max=arr[0];
    for ( i = 1; i < SIZE; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    printf("\nThe minimum is %d and the maximum is %d",min,max);
    return 0;
}