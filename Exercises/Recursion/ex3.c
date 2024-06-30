/**
*   Write a recursive function that prints the first 50 natural numbers
*/
#include <stdio.h>

void print_50N(int n)
{
    if (n==51)
    {
        return;
    }else
    {
        printf("%d ",n);
        print_50N(n+1);
    }
}

int main(void)
{
    printf("\n50 natural numbers: ");
    print_50N(1);
    return 0;
}
