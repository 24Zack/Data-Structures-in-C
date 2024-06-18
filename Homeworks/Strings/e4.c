/**
 * Creating my own strcpy() function and Mystrlen()
*/
#include <stdio.h>
#include <string.h>

void My_strcpy(char *, const char *);
int My_strlen(const char *);

int main(void)
{
    //declarations
    char word[30],cpy[30];
    printf("\nEnter a word> ");
    scanf("%s",word);
    My_strcpy(cpy,word);
    printf("\nThe copy of %s is %s",word,cpy);
    return 0;
}

void My_strcpy(char *dest, const char *src)
{
    //local declarations
    unsigned short i=0;
   for ( i = 0; i < My_strlen(src); i++)
   {
    dest[i]=src[i];
   }
   dest[i]='\0';
   
}

int My_strlen(const char *str)
{
    int cnt=0;
    while (str[cnt]!='\0')
    {
        cnt++;
    }
    return cnt;
}