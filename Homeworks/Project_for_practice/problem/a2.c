/**
 * Find the number of char in this file
*/
#include <stdio.h>

int main(void)
{
    //declarations
    FILE *outfp;
    char c;
    int count=0;
    outfp=fopen("a.txt","r");
    if (outfp==NULL)
    {
        printf("\nThe file was not found");
        return 1;
    }
    while (!feof(outfp))
    {
        fscanf(outfp,"%c",&c);
        count++;
    }
    printf("\nThere are %d char in the file",count);

    fclose(outfp);
    return 0;
}