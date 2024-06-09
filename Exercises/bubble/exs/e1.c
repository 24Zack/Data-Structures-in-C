/**
 * Write a C program to input elements in an array and reverse the array using pointers. 
 * How to reverse an array using pointers in C programming. 
 * Logic to reverse an array using pointers in C.
*/
#include <stdio.h>

void Bubble_sort(int *arr, int n);
void swap(int *arr,int j);

int main(void)
{
    //local declarations
    int arr[10],no,i;
    //input
    do
    {
        printf("\nEnter the size of the array (max 10)> ");
        scanf("%d",&no);
    } while (no>10);
    //input array
    for ( i = 0; i < no; i++)
    {
        printf("\nEnter the %d element of the array> ",i+1);
        scanf("%d",&arr[i]);
    }
    
    Bubble_sort(arr,no);
    //output sort
    for ( i = 0; i < no; i++)
    {
        printf("%d ",arr[i]);
    }
    

    
    return 0;
}

void Bubble_sort(int *arr, int n)
{
    //local declarations
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = n-1; j >i ; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr,j);
            }
            
        }
        
    }
    
}

void swap(int *arr,int j)
{
    int temp;
    temp=arr[j];
    arr[j]=arr[j-1];
    arr[j-1]=temp;
}