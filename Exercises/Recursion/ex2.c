/**
 * Write a recursive function ‘sum(int n)’
that calculates the sum of successive
integers starting at 1 and ending at n
[sum(n) = 1+2+…+n]
*/
#include <stdio.h>
int sum(int N);
int main(void)
{
    //declarations
    int tot;
    int n=3;
    tot=sum(n);
    printf("\nSum: %d",tot);
    return 0;
}

int sum(int N)
{
    if (N==1)
    {
        return 0;
    }else
    {
        return (sum(N-1)+N);
    }
    
    
}