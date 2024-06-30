/**
 * Assume that we want to a list of
students into a hash table using their
IDs. The following program represent
how collision is solved using separate
chaining.
◼ We are using a table of 10 cells
◼ We are using ID%Size as a hash function
◼ Implement this code
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
typedef enum
{
    Hash=1,
    Delete=2,
    Search=3,
    Print_hash_table=4,
    QUIT=5
}menu_t;

typedef struct tag
{
    char name[20];
    int ID;
    struct tag *next;
}node;


//  Functions prototypes
void initialize_HT(node **,int);
void Add(node**,node*,int);
node* delete(node**,int,int);
void Display(node **, int);
node* create_nd();
int HF(int,int);
int check_empty_HT(node**,int);

//  main

int main(void)
{
    //declarations
    int choice;

    //  to be completed, but the most important part are the functions,
    //  it's just a hash table implemented using linked lists
    return 0;
}

void initialize_HT(node **arr,int N)
{
    //  local declarations
    int i;
    for ( i = 0; i < N; i++)
    {
        arr[i]=NULL;
    }
}
int HF(int key,int table_size)
{
    return (key%table_size);
}

void Add(node**arr,node*toAdd,int index)
{
    if (arr[index]==NULL)
    {
        arr[index]=toAdd;
    }else
    {
        toAdd->next=arr[index];
        arr[index]=toAdd;
    }

}

node* delete(node**arr,int ID,int index)
{
    //  local declarations
    node *temp,*walker;
    if (arr[index]==NULL)
    {
        return NULL;
    }else
    {
        walker=arr[index];
        if (walker->ID==ID)
        {
            arr[index]=walker->next;
            return walker;
        }else
        {
            while (walker!=NULL)
            {
                if (walker->next->ID==ID)
                {
                    temp=walker->next;
                    walker->next=temp->next;
                    return temp;
                }else
                {
                    walker=walker->next;
                }
            }
            return NULL;
        }
    }
}

void Display(node **HT, int N)
{
    int i;
    node *walker;
    for ( i = 0; i < N; i++)
    {
        walker=HT[i];
        while (walker!=NULL)
        {
            printf("\nName: %s, ID:%d",walker->name,walker->ID);
            walker=walker->next;
        }


    }

}

int check_empty_HT(node**HT,int size)
{
    int i;
    for ( i = 0; i < size; i++)
    {
        if (HT[i]!=NULL)
        {
            return 1;
        }

    }
    return 0;
}

node* create_nd()
{
    node* new;
    new=(node*)malloc(sizeof(node));
    new->next=NULL;
    printf("\nWhat's the student's name: ");
    gets(new->name);
    printf("\nWhat's his ID: ");
    scanf("%d",&new->ID);
    return new;
}
