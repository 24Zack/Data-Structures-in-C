/**
 * Creating my own strlen() function
*/
#include <stdio.h>

int My_strlen(char *);
int main(void)
{
    //declarations
    char word[30];
    int size;
    //input
    printf("\nInput a word> ");
    scanf("%s",word);
    size=My_strlen(word);
    printf("\nThe word %s is of size %d",word,size);
    return 0;
}

int My_strlen(char *str)
{
    int cnt=0;
    while (str[cnt]!='\0')
    {
        cnt++;
    }
    return cnt;
}