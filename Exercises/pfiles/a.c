#include <stdio.h>

int main(void)
{
    //declarations
    char string[30];
    FILE *p;
    p=fopen("a.txt","r");
    if (p==NULL)
    {
        p=fopen("a.txt","w");
    }
    
    fgets(string,30,p);
    printf("\n%s",string);
    fclose(p);
}