/**
 * Define a function used to find the minimun in a given array using recursion
*/
#include <stdio.h>
int min;

int find_min(int *arr, int n)
{
    // if (n!=0)
    // {
    //     if (arr[0]<arr[n])
    //     {
    //         arr[n]=arr[0];
    //     }
    //     find_min(arr,n);
        
    // }
    if (n==0)
    {
        return min;
    }else
    {
        if (arr[0]<arr[n])
        {
            arr[n]=arr[0];
        }
        min =find_min(arr+1,n-1);
    }
    
}


int main(void)
{
    //declarations
    int arr[]={12,2,3,1,0,9};
    
    find_min(arr,5);
    printf("min: %d",min);
    return 0;
}