#include <stdio.h>
#include <stdlib.h>
typedef struct nd{
    int id;
    char name[30];
    struct nd*next;
}node;

void fiLL(node *n);

int main(void)
{
    //declaraions
    node *head=NULL,*walker,*new_node;
    char dec;
    do
    {
        fflush(stdin);
        new_node=(node*)malloc(sizeof(node));
        //fill
        fiLL(new_node);
        if (head==NULL)
        {
            head=new_node;
        }else
        {
            walker=head;
            while (walker->next!=NULL)
            {
                walker=walker->next;
            }
            walker->next=new_node;
            
        }
        printf("\nDo you want to add a new node: ");
        scanf("%c",&dec);
        
    } while (dec=='y'||dec=='Y');
    //output
    walker=head;
    while (walker!=NULL)
    {
        printf("\nName: %s",walker->name);
        printf("\nID: %d",walker->id);
        walker=walker->next;
    }

    return 0;
}

void fiLL(node *n)
{
    printf("\nEnter the name: ");
    gets(n->name);
    printf("\nEnter the ID: ");
    scanf("%d",&n->id);
    n->next=NULL;
    fflush(stdin);
}