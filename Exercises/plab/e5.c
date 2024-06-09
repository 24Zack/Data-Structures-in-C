/**
 * 5. Write a program in C to count the total number of duplicate elements in an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 5
element - 1 : 1
element - 2 : 1
Expected Output :
Total number of duplicate elements found in the array is : 1
*/
#include <stdio.h> 
#define SIZE 5
int main(void)
{
    //declarations
    int arr[SIZE],i,no_duplicates=0,j;
    printf("\nInput %d elements in the array",SIZE);
    for ( i = 0; i < SIZE; i++)
    {
        printf("\nelement - %d > ",i+1);
        scanf("%d",&arr[i]);
    }
    //check no_duplicate
    
    for ( i = 0; i < SIZE; i++)
    {
        
        for ( j = (i+1); j < SIZE; j++)
        {
            if (arr[i]==arr[j])
            {
                no_duplicates++;
                printf("\n%d=%d",arr[i],arr[j]);
                break;
            }
            
        }
        
    }

    printf("\nTotal number of duplicate elements found in the arrays is : %d\n",no_duplicates);

    return 0;
}