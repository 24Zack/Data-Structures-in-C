/**
 * read a specific line from a file
*/
#include <stdio.h>
typedef enum{false,true}bool;

int main(void)
{
    //declarations
    FILE *infp;
    char buffer[100];
    int n,i=1,t=0;
    infp=fopen("a.txt","r");
    if (infp==NULL)
    {
        printf("\nSorry, file impossible to read");
        return true;
    }
    printf("\nEnter the line you want to read: ");
    scanf("%d",&n);
    while (fgets(buffer,100,infp)!=NULL)
    {
        if (i==n)
        {
            //line found
            t=1;
            break;
        }
        i++;
    }
    if (t==1)
    {
        printf("\nLine content:\n%s\n",buffer);
    }else
    {
        printf("\nThe line was not found");
        
    }


    fclose(infp);
    return 0;
}