/**
 * Define a function that will load the content of the file to a 2D array of char.
 * You can close the file.
 * Define a second function that will return the number of credits you are
 * taking this semester. Remember, a lab has zero credits!
*/
#include <stdio.h>
#include <string.h>

void load_content(char arr[][50],FILE *);
void debug(char arr[][50]);
int find_no_credits(char arr[][50]);

int main(void)
{
    //declaration
    char arr[10][50];
    FILE *infp;
    int no_credits;
    infp=fopen("courses.txt","r");
    if (infp==NULL)
    {
        printf("\nThe file you indicated doesn't exist");
        return -1;
    }
    //load content
    load_content(arr,infp);
    fclose(infp);
    //ouput content
    debug(arr);

    /*      Call second function        */
    no_credits=find_no_credits(arr);
    if (!no_credits)
    {
        printf("\nYou are taking 0 credits or there is an error");
        return 1;
    }
    printf("\nYou are taking %d credits this semester",no_credits);
    
    return 0;
}

void load_content(char arr[][50],FILE *f)
{
    //local declarations
    int i=0;
    char course[50];
    while (!feof(f))
    {
        fscanf(f,"%s",arr[i]);
        i++;
    }
}

int find_no_credits(char arr[][50])
{
    //local declarations
    int count=0,i,n;
    //redirect the cursor
    
    for ( i = 0; i < 7; i++)
    {
        if (strlen(arr[i])>7)
        {
            continue;
        }
        char c=arr[i][4];
        n=c-'0'; //ASCI code susbtraction which results into the real value of the number
        count+=n;
    }
    return count;

}

void debug(char arr[][50])
{
    //local declarations
    int i;
    printf("\n---------------------");
    printf("\nStrings:\n");
    for ( i = 0; i < 7; i++)
    {
        printf("\n%s",arr[i]);
    }
    printf("\n---------------------");
}