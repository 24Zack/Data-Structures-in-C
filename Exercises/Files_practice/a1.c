/**
 * I'm going to read from the file 
*/
#include <stdio.h>

int main(void)
{
    //declarations
    FILE*p;
    char str[50];
    p=fopen("a.txt","r");
    if (p==NULL)
    {
        p=fopen("a.txt","w");//creating file
    }
    while (!feof(p))
    {
        fgets(str,50,p);
        printf("\n%s",str);
    }
    
    fclose(p);
}
