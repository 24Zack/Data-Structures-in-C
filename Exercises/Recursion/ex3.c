/**
 * 2. Write a program in C to calculate the sum of numbers from 1 to n using recursion.
Test Data :
Input the last number of the range starting from 1 : 5
Expected Output:

The sum of numbers from 1 to 5 : 
15
*/
#include <stdio.h>

int sum(int n)
{
    if (n==0)
    {
        return 0;
    }else
    {
        return (n+sum(n-1));
    }
}

int main(void)
{
    int s=sum(5);
    printf("\nResult: %d",s);
    return 0;
}