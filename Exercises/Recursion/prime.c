/**
 * C Exercises: Check a number is a prime number or not
*/
#include <stdio.h>

int check_prime(int n, int i)
{
    if (n<=1)
    {
        return 0;
    }else if (i==n)
    {
        return 1;   
    }else
    {
        if (n%i==0)
        {
            return 0;
        }
        return check_prime(n,i+1);
           
    }   
}

int main(void)
{
    //declarations
    int n=3;
    if (check_prime(n,2))
    {
        printf("\n %d is prime",n);
    }else
    {
        printf("\n %d is not prime",n);
    }
    
    return 0;
}