/**
 * Bubble sort like me= my method
*/
#include <stdio.h> 

void swap(int *a, int i);
void print_arr_content(const int *ar, int n);

int main(void)
{
    //declarations
    int arr[20],i,j,no;
    //input
    do
    {
       printf("\nHow many elements would you like to have (max 20)> ");
       scanf("%d",&no); 
    } while (no>20);
    
    for ( i = 0; i < no; i++)
    {
        printf("\nEnter the value of the %d element of the array> ",i+1);
        scanf("%d",&arr[i]);
    }
    //print existing array
    printf("\n--------------------------------------");
    printf("\n");
    for ( i = 0; i < no; i++)
    {
        printf("|%d ",arr[i]);
    }
    printf("\n--------------------------------------");
    printf("\n");

    //sorting the array
    for ( i = 0; i < no-1; i++)
    {
        for ( j = 0; j < no-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr,j);

            }
            printf("\nindex : %d",i);
            print_arr_content(arr,no);
            
        }
        
    }
    //display sorted array
    printf("\nSorted array: ");
    for ( i = 0; i < no; i++)
    {
        printf("%d, ",arr[i]);
    }

    return 0;
}

void swap(int *a, int i)
{
    //local declarations
    int temp;
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
}

void print_arr_content(const int *ar, int n)
{
    //local declarations
    int i;
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        printf("|%d ",ar[i]);
    }
    printf("\n");
}