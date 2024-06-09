/**
 * Check if a string is a palindrome using recursion
*/
#include <stdio.h>
#include <string.h>

int ispalindrome(char *str,int start, int end)
{
    if (start>=end)
    {
        return 1;
    }else
    {
        if (str[start]==str[end])
        {
            ispalindrome(str,start+1,end-1);
        }else
        {
            return 0;
        }
    }
}


int main(void)
{
    //declarations
    char palin[30];
    printf("\nEnter a word: ");
    scanf("%s",palin);
    if (ispalindrome(palin,0,strlen(palin)-1))
    {
        printf("\n %s is a palindrome",palin);
    }else
    {
        printf("\n %s is not a palindrome",palin);
    }
    
    return 0;
}