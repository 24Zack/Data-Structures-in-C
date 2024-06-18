/**
 * A comma separated values file, is a text file that has data stored
 * in a set of lines where the fields of each line are separated using a comma.
 * This organization facilitates importing data to a table. Consider this line:
 * Australia,6,Canberra,Sydney,2569
 * 
 * This line has data about: Country name,rank largest countries,
 * capital,largest city, population in millions
 * Copy this line to a text file then define a function that will change the
 * content of the file so that data will be stored as follows:
 * 
 * Australia
 * 6
 * Canberra
 * Sydney
 * 2569
*/
#include <stdio.h>
#include <string.h>

void change_file(FILE *);

int main(void)
{
    //declarations
    FILE *infp;
    infp=fopen("country.txt","r+");
    if (infp==NULL)
    {
        printf("\nThe file provided doesn t exist");
        return 1;
    }else
    {
        change_file(infp);
        fclose(infp);
    }
    
    return 0;
}

void change_file(FILE *outfp)
{
    //local declaration
    char arr[100];
    fgets(arr,100,outfp);
    fseek(outfp,0,0);//set to 0
    char *token=strtok(arr,",");
    while (token!=NULL)
    {
        fprintf(outfp,"%s\n",token);
        token=strtok(NULL,",");
    }
    
}