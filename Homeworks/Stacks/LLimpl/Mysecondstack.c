#include <stdio.h>
#include <stdlib.h>
typedef struct nd{
    char ch;
    struct nd *next;
}node;
//prototypes
void push(node **,node*);
char pop(node**);

int main(void)
{
    //declarations
    node *top=NULL;
    return 0;
}

void push(node **top,node*topush)
{
    topush->next=*top;
    *top=topush;
}

char pop(node**top)
{
    //local declarations
    node *temp;
    char c;
    temp=*top;
    c=temp->ch;
    (*top)=temp->next;
    free(temp);
    return c;
}
