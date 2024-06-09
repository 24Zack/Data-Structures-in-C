/**
 * Write a C program to input elements in array and search an element in array using pointers.
 * How to search an element in array using pointers in C programming. 
 * Logic to search an element in array using pointers in C program.
*/
#include <stdio.h>
#define SIZE 5
typedef enum{false,true}bool;

int find_el(int *ptr, int num);

int main(void)
{
    //declarations
    int arr[SIZE],i,no;
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of the %d element> ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the number you want to search in the array> ");
    scanf("%d",&no);
   
    
    if (find_el(arr,no))
    {
        printf("\n%d does exist in the array!",no);
    }else
    {
        printf("\n%d does not exist in this array",no);
    }
    
    
    return 0;
}

int find_el(int *ptr, int num)
{
    int i;
    for ( i = 0; i<sizeof(ptr); i++)
    {
        if (*(ptr+i)==num)
        {
            return true;
        }
        
    }
    return false;
}