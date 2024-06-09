/**
 * 5. Write a program in C to count the digits of a given number using recursion. >
Test Data :
Input a number : 50
Expected Output :

The number of digits in the number is :  2
*/
#include <stdio.h>

int count_digits(int n)
{
    n/=10;
    if (n!=0)
    {
        return (1+count_digits(n));
    }else
    {
        return 1;
    }
    
}
int main(void)
{
    //declarations
    int n=30;
    int dig;
    dig=count_digits(n);
    printf("\ndigits of %d: %d",n,dig);
    return 0;
}