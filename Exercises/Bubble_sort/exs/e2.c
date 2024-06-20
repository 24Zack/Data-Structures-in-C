/**
 * Write a C program to input elements in an array and sort array using pointers. 
 * How to sort an array in ascending or descending order using function pointers in C programming. 
 * Logic to sort an array using pointers in program.
*/
#include <stdio.h>

void bubble_sort(int *arr,int n);

void swap(int *a, int *b);

int main(void)
{
    //declarations
    int i,arr[20],n;
    //input arr
    do 
    {
        printf("\nEnter the size of the array (max 20)> ");
        scanf("%d",&n);
    } while (n>20);
    for ( i = 0; i < n; i++)
    {
        printf("\nEnter the value of the %d element> ",i+1);
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    //output array
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}

void bubble_sort(int *arr,int n)
{
    //local declarations
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j=n-1; j>i ; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(&arr[j],&arr[j-1]);
            }
            
        }
        
        
    }
    
}

void swap(int *a, int *b)
{
    //local declarations
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
