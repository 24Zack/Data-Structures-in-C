#include <stdio.h>
#define size 10

//prototypes
int push(char *stack,char Topush,int*top);
char pop(char *stack,int*top);
void traverse_stack(char *stack,int top);

int main(void)
{
    //declarations
    char stack[10]={'A','B','c','d','f'};
    int top=4;
    char c;
    printf("\nStack before: ");
    traverse_stack(stack,top);
    printf("----------------\n");
    printf("\nEnter the character you want to push: ");
    scanf("%c",&c);
    printf("----------------\n");
    printf("\nStack after pushing: ");
    if (push(stack,c,&top))
    {
        traverse_stack(stack,top);
    }else
    {
        printf("\nError pushing");
    }
    printf("\n----------------");
    printf("\nStack after popping: ");
    if (pop(stack,&top)!='<')
    {
        traverse_stack(stack,top);
    }else
    {
        printf("\nError popping");
    }
    return 0;
}

int push(char *stack,char Topush,int*top)
{
   if (*top==size-1)
   {
    return 0;
   }else
   {
    stack[++(*top)]=Topush;
    return 1;
   }
}

char pop(char *stack,int*top)
{
    //declarations
    char c;
    if (*top==size-1)
    {
        return '£';
    }else
    {
        return stack[(*top)--];
    }
}

void traverse_stack(char *stack,int top)
{
    //declarations
    int i;
    for ( i = 0; i < top+1; i++)
    {
        printf("\nChar: %c",stack[i]);
    }
    printf("\n");
}
