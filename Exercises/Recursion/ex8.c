/**
 * C program using recursion to find the number of time a character occurs in a string
*/
#include <stdio.h>
#include <string.h>

int find_no_occurences(char *, char);

int main(void)
{
    //declarations
    int result;
    result = find_no_occurences("Helwlo",'l');
    printf("\nNo. of occurences: %d",result);

    return 0;
}

// int find_no_occurences(char *str, char ch){
//     //local declarations
//     int occurences;
//     if (str[0]=='\0')
//     {
//         occurences=0;
//     }else if (str[0]==ch)
//     {
//         occurences = 1+find_no_occurences(&str[1],ch);
//     }else
//     {
//         occurences = find_no_occurences(&str[1],ch);
//     }
    
//     return occurences;
// }
//OR

int find_no_occurences(char *str, char ch){
    
    if (str[0]=='\0')
    {
        return 0;
    }else
    {
        if (str[0]==ch)
        {
            return (1 + find_no_occurences(++str,ch));
        }else
        {
            return find_no_occurences(++str,ch);
        }
        
    }
    
    
}