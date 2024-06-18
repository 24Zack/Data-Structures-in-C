#include <stdio.h>
#include <stdlib.h>
typedef struct nd{
    int id;
    char name[50];
    struct nd *next;
    struct nd *previous;
}node;

void add(node **,node*);
void fill(node *);
void printLL(node *head);

int main(void)
{
    //declarations
    node *head=NULL;
    node *new_nd;
    int i=0;

    do
    {
        new_nd=(node *)malloc(sizeof(node));
        //fill
        fill(new_nd);
        add(&head,new_nd);
        i++;
    } while (i<3);
    //print
    printLL(head);

    return 0;
}

void add(node **head,node*ToAdd)
{
    //local declarations
    node *walker;
    if (*head==NULL)
    {
        *head=ToAdd;
    }else
    {
        walker=*head;
        while (walker->next!=NULL)
        {
            walker=walker->next;
        }
        walker->next=ToAdd;
        ToAdd->previous=walker;
        
    }
    
    
}

void printLL(node *head)
{
    //local declarations
    node *walker=head;

    while (walker!=NULL)
    {
        printf("\nName: %s",walker->name);
        printf("\nID: %d",walker->id);
        walker=walker->next;
    }
    
    
}
void fill(node *node)
{
    fflush(stdin);
    printf("\nEnter the name: ");
    gets(node->name);
    fflush(stdin);
    printf("\nEnter the ID: ");
    scanf("%d",&node->id);
    node->next=NULL;
    node->previous=NULL;

}