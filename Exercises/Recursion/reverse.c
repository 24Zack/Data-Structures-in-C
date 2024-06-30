/**
 * Reverse an array using recursion
*/
#include <stdio.h>

void reverse(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }else
    {
        int temp;
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        reverse(arr,start+1,end-1);
    }


}

int main(void)
{
    //declarations
    int arr[]={12,32,22,1};
    int n=4;
    printf("\nOriginal: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    reverse(arr,0,n-1);
    printf("\nReverse: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}
