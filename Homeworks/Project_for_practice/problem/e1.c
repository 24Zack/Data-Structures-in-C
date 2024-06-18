/**
 * First exercise in the powerpoint
*/
#include <stdio.h>

int main(void)
{
    //declaration
    FILE *outfp;
    char buffer[100];
    outfp=fopen("a.txt","r");
    if (outfp==NULL)
    {
        printf("\nerror openiong the file");
        return 1;
    }
    printf("\nContent: ");
    while (fgets(buffer,100,outfp)!=NULL)
    {
        printf("%s\n",buffer);
    }


    fclose(outfp);
    return 0;
}