/**
 * 14. Write a program in C to print even or odd numbers in a given range using recursion. >
Test Data :
Input the range to print starting from 1 : 10
Expected Output :

All even numbers from 1 to 10 are : 2  4  6  8  10                              
All odd numbers from 1 to 10 are : 1  3  5  7  9   
*/
#include <stdio.h>

void print_even_or_ODD(int n, int range)
{
    if (n<=range)
    {
        printf("\n%d ",n);
        print_even_or_ODD(n+2,range);
    }
    
}

int main(void)
{
    //declarations
    int range=10;
    printf("\nOdd: ");
    print_even_or_ODD(1,range);
    printf("\nEven: ");
    print_even_or_ODD(2,range);

    return 0;
}