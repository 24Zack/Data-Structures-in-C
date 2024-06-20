/**
 * Video exercise
 * 2nd video
 * Inputting 5 names in a 2d array then sorting alpahbetically
 * --> We're trying to use strcmp to understand how it works
*/
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 20
#define MAX_CHAR 20

void fill(char dest[][MAX_CHAR], int n);

void sort_names(char dest[][MAX_CHAR],int n);

void swap(char dest[][MAX_CHAR],int j);

void display(const char dest[][MAX_CHAR],int n);

int main(void)
{
    //declarations
    char names[MAX_WORDS][MAX_CHAR];
    int n=5;
    fill(names,n);
    printf("\nBefore sorting:\n");
    display(names,n);
    sort_names(names,n);
    printf("\nAfter sorting:\n");
    display(names,n);
    return 0;
}

void fill(char dest[][MAX_CHAR], int n)
{
    //declarations
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("\nEnter the %d name> ",i+1);
        gets(dest[i]);
    }
    
}

void sort_names(char dest[][MAX_CHAR],int n)
{
    //local declarations
    int x,i,j;

    for ( i = 0; i < n-1; i++)
    {
        for ( j = n-1; j >i; j--)
        {
            if (strcmp(dest[j],dest[j-1])<0)
            {
                swap(dest,j);
            }
            
        }
        
    }
    
}

void swap(char dest[][MAX_CHAR],int j)
{
    char temp[MAX_CHAR];
    strcpy(temp,dest[j]);
    strcpy(dest[j],dest[j-1]);
    strcpy(dest[j-1],temp);
    
}

void display(const char dest[][MAX_CHAR],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("\nName %d: %s",i+1,dest[i]);
    }
    
}