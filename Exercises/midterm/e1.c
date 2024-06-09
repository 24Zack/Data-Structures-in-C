/**
 * Check if a word comes more than one time in a file
*/
#include <stdio.h>
#include <string.h>

int appear_more_than_once(FILE *,char *word);

int main(void)
{
    //declararatioons
    FILE *infp;
    int count=0;
    char word[100];
    infp=fopen("data.txt","r");
    if (infp==NULL)
    {
        printf("\nThe file doesn't exist");
        return 1;
    }
    
    printf("\nEnter the word: ");
    gets(word);
    count=appear_more_than_once(infp,word);
    printf("\nThe word %s occured %d times in the file",word, count);
    fclose(infp);
    return 0;
}

int appear_more_than_once(FILE *infp,char *word)
{
    //declarations
    int count=0;
    char buffer[100];
    
    while (!feof(infp))
    {
        fscanf(infp,"%s",buffer);
        if (strcmp(word,buffer)==0)
        {
            count++;
        }
        
    }
    return count;
}