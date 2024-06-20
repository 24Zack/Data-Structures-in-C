/**
 * Bubble sort, different method, but still O(n2)
*/
#include <stdio.h>

void swap(int *ar,int j);
void print_arr_content(const int *ar, int n);

int main(void)
{
    //declarations
    int i,j,arr[20],no;
    //input
    do
    {
     printf("\nEnter the size of the array (max 20)> ");
     scanf("%d",&no);   
    } while (no>20);

    for ( i = 0; i < no; i++)
    {
        printf("\nEnter the value of the %d element> ",i+1);
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
    
    //sorting 
    for ( i = 0; i < no-1; i++)
    {
        for ( j = no-1; j >i; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr,j);
            }
            printf("\nindex : %d",i);
            print_arr_content(arr,no);
            
        }
        
    }
    //output
    printf("\n");
    for ( i = 0; i < no; i++)
    {
        printf("%d, ",arr[i]);
    }
    
    
    return 0;
}

void swap(int *ar,int j)
{
    //local declarations
    int temp;
    temp=ar[j];
    ar[j]=ar[j-1];
    ar[j-1]=temp;
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
