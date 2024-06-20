/**
 * Use a STACK (array implemented) to check wether a given string is a palindrome
*/
#include <stdio.h>
#include <string.h>

//Function prototypes
int check_palindrome(char *stack,int *top,char *to_check);
int push(char *stack, int *top, int size, char topush);
char pop(char *stack,int *top);

int main(void)
{
    //declarations
    int top=-1;
    char *stack,word[20],ans[4],c;
    do
    {
        printf("\nEnter a word to check: ");
        scanf("%s",word);
        stack=(char *)calloc(strlen(word),sizeof(char));
        if (check_palindrome(stack,&top,word))
        {
            printf("%s is a palindrome",word);
        }else
        {
           printf("%s is not a palindrome",word); 
        }
        
        //ask if the user wants to continue
        printf("\n------------------------------------");
        printf("\nDo you want to continue Yes/No: ");
        scanf("%s",ans);
        getchar();

    } while (strcmp(ans,"No")!=0);
    
    return 0;
}

int push(char *stack, int *top, int size, char topush)
{
    if (*top==size-1)
    {
        return 0;
    }else
    {
        stack[++(*top)]=topush;
        return 1;
    }
    
}

char pop(char *stack,int *top)
{
    if (*top==-1)
    {
        return '$';
    }else
    {
        return (stack[(*top)--]);
    }
    
}

int check_palindrome(char *stack,int *top,char *to_check)
{
    //local declarations
    int i=0,flag=1;
    char popped_char;

    //push all the word characters into the stack 
    for ( ; i < strlen(to_check); i++)
    {
        push(stack,top,strlen(to_check),to_check[i]);
    }
    i=0;
    while (flag)
    {
        popped_char=pop(stack,top);
        if (popped_char=='$')
        {
        break; //we popped every char from the stack, thus to_check is a palindrome
        }else if (popped_char!=to_check[i])
        {
        flag=0;
        break;
        }   
        i++;
    }
    if (flag)
    {
        return 1;
    }else
    {
        return 0;
    }

}
