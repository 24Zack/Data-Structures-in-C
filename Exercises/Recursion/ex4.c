/**
 * Write a function that calculates the sum of an array recursively
*/
#include <stdio.h>

int sum_arr(int *arr, int n);

int main(void)
{
    //declarations
    int arr[4]={10,30,20,33};
    int sum;
    sum=sum_arr(arr,4);
    printf("\nSum: %d",sum);
    return 0;
}

int sum_arr(int *arr, int n)
{
    if (n==0)
    {
        return 0;
    }else
    {
        return (arr[0]+sum_arr(arr+1,n-1));
    }
}