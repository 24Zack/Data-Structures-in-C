/**
 * Exercise 1: Copy the following definition to a text file and name it cloud.txt
Define a function that will search if a keyword is mentioned in the file or
not
*/
#include <stdio.h>
#include <string.h>

int find_keyword(FILE *myfile,char *keyword);

int main(void)
{
    //declarations
    FILE *outfp;
    int status;
    char keyword[40];
    outfp=fopen("cloud.txt","r");
    if (outfp==NULL)
    {
        outfp=fopen("cloud.txt","w");
    }
    
    //input
    printf("\nEnter a keyword> ");
    scanf("%s",keyword);
    status=find_keyword(outfp,keyword);
    if (!status)
    {
        printf("\nThe keyword %s was not found in the text file",keyword);
        fclose(outfp);
        return 1;
    }
    printf("\nThe keyword %s was found in the text file",keyword);

    fclose(outfp);
    return 0;
}   

int find_keyword(FILE *myfile,char *keyword)
{
    //local declarations
    char word[40];
    while (!feof(myfile))
    {
        fscanf(myfile,"%s",word);
        if (strcmp(word,keyword)==0)
        {
            return 1;
        }
        
    }
    return 0;
}