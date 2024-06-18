/**
 * We would like to write a C program that keeps reading words from the user and store them in an arrays of strings. 
 * Your program should stop reading words when the user input "stop" as a word.
 * Make sure that you display all the words in the array excluding the word "stop"
*/
#include <stdio.h> 
#include <string.h>
#define MAX_WORDS 20
#define LENGHT 20

int main(void)
{
    //declarations
    char words[MAX_WORDS][LENGHT];
    int i=0,n=MAX_WORDS;
    //input
    do
    {
        printf("\nEnter a word (type stop if you want to stop)> ");
        gets(words[i]);
        i++;
    } while (i>n || strcmp(words[i-1],"stop") !=0);
    i=0;
    //display
    
    while (strcmp(words[i],"stop")!=0)
    {
        printf("\nwords %d: %s",i+1,words[i]);
        i++;
    }
 
    return 0;
}