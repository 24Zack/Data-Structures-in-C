#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nd{
    int id;
    char name[40];
    struct nd*next;
}node;
void fill(node *n);
void add_node(node **,node**tail,node *new_node);

int main(void)
{
    //declarations
    node *head=NULL,*tail=NULL,*walker;
    node *new_nd;
    char dec;
    do
    {
        new_nd=(node*)malloc(sizeof(node));
        //fill
        fill(new_nd);
        //attach
        if (head==NULL)
        {
            head=new_nd;
            tail=new_nd;
        }else
        {
            add_node(&head,&tail,new_nd);
        }
        //prompt user
        fflush(stdin);
        printf("\nDo you want to continue: ");
        scanf("%c",&dec);

    } while (dec=='y'||dec=='Y');
    //display
    walker=head;
    while (walker!=NULL)
    {
        printf("\n------------------------");
        printf("\nName: %s",walker->name);
        printf("\nID: %d",walker->id);
        walker=walker->next;
    }
    
    return 0;
}

void fill(node *n)
{
    fflush(stdin);
    printf("\nEnter the name: ");
    gets(n->name);
    fflush(stdin);
    printf("\nEnter the ID: ");
    scanf("%d",&n->id);
    n->next=NULL;
}

void add_node(node **head,node **tail,node *new_node)
{
    if (*head==NULL)
    {
        *head=new_node;
        *tail=new_node;
    }
    
    (*tail)->next=new_node;
    *tail=(*tail)->next;
}