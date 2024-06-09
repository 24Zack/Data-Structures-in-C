/**
 * strcmp(); practice
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    //declarations
    char name1[]="Fouthon";
    char name2[]="Fouton";
    int x;
    x=strcmp(name1,name2);
    if (x==0)
    {
        printf("\nThe two keywords are the same, value: %d",x);
    }else if (x<0)
    {
        printf("\n %s comes before %s in the alphabetic order value: %d ",name1,name2,x);
    }else
    {
        printf("\n %s comes before %s in the alphabetic order value: %d ",name2,name1,x);
    }
    
    
    return 0;
}