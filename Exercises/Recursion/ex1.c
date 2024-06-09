/**
 * OK.
*/
#include <stdio.h>

int fun(int n)
{
    int x=1,k;
    if (n==1)
    {
        return x;
    }
    for ( k = 0; k < n; ++k)
    {
        x=x+fun(k)*fun(n-k);
    }
    return x;
    
}
int main(void)
{
    fun(4);
    return 0;
}