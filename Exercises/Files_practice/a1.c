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
        return 1;   //  file does not exist
    }
    while (!feof(p))
    {
        fgets(str,50,p);
        printf("\n%s",str);
    }

    fclose(p);
    return 0;
}
