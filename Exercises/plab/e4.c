/**
 * 1.⁠ ⁠Write a complete C program to delete an element from an array at a specific position (index).
 * The program should print an error message if the index is invalid. 
*/
#include <stdio.h>
#define SIZE 5

int main(void)
{
    //declarations
    int arr[SIZE],in,i;
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of the %d element of the array> ");
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the index where you want to delete the element> ");
    scanf("%d",&in);
    if (in<0 || in>=SIZE)
    {
        printf("\nIndex is invalid");
        return 0;
    }
    

    
   
    return 0;
}