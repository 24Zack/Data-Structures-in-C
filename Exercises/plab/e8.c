/**
 * Write a C program to input elements in an array and sort array using pointers.
 * How to sort an array in ascending or descending order using function pointers in C programming. 
 * Logic to sort an array using pointers in program.
*/
#include <stdio.h>
#define SIZE 6
typedef enum{false,true}bool;

void ascending(int *ptr,int *ass);
void descending(int *ptr,int *dess);
void swap();


int main(void)
{
    //declarations
    int arr[SIZE],i,asc[SIZE],desc[SIZE];
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of the %d element> ",i+1);
        scanf("%d",&arr[i]);
    }
    
    //print ascending order
    printf("\nAscending order:\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d, ",asc[i]);
    }
    
    
    return 0;
}

void ascending(int *ptr, int *ass)
{
    //declarations
    unsigned short i,j;
    
    
    
}

void descending(int *ptr, int *dess)
{
    //declarations
    unsigned short i;


}

void swap()
{

}