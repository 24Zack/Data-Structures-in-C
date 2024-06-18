#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nd{
  char name[50]; 
  char city[50];
  int ranking; 
  struct nd*next;
  struct nd*previous;
}node;

void menu(void); 
void traverse_LL(node*);
node * createLL(FILE *);
void add_node(node**,node*);
int delete_node(node**,char*);
int update_rank(node **,char *,int);
void add_LL(node **);


/*         Main Function        */
int main(void){
  int choice,f_info=0,new_rank; 
  char ToDelete[30],ToUpdate[50]; 
  node*head=NULL,*new_node;
  FILE *infp;
  infp=fopen("input.txt","r");
  if (infp==NULL)
  {
    printf("\nThis file is not in the right directory");
    return 1;
  }
      
   do{

      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:
      if (!f_info)
      {
       head=createLL(infp);
       f_info=1; 
      }
		       break;
	    case 2:
      if (f_info)
      {
        fflush(stdin);
        printf("\nEnter the name: ");
        gets(ToDelete);
        fflush(stdin);
        if (delete_node(&head,ToDelete))
        {
          printf("\n%s was successfully deleted from the LL",ToDelete);
        }else
        {
          printf("\n%s was not found in the LL",ToDelete);
        }
      }else
      {
        printf("\nFill the array first");
      }
		       break;
	    case 3:
        traverse_LL(head);
		       break;
	    case 4:
        fflush(stdin);
        printf("\nEnter the name of the university: ");
        gets(ToUpdate);
        fflush(stdin);
        printf("\nEnter the new rank: ");
        scanf("%d",&new_rank);
        if (update_rank(&head,ToUpdate,new_rank))
        {
            printf("\n%s's rank was successfully updated",ToUpdate);
        }else
        {
            printf("\n%s's rank was not updated",ToUpdate);
        }
		       break;
      case 5:
      add_LL(&head);
		       break;
	    case 6:printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
               break;
	    default:printf("\n\t\tThat was an INVALID CHOICE!\n");
	  }//end of switch
   }while(choice!=6);

  fclose(infp);    
  return 0;
}

/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Create LL\n");
  printf("\n\t\t2. Delete a Node from a LL\n");
  printf("\n\t\t3. Traverse a LL\n");
  printf("\n\t\t4. Update a university ranking\n");
  printf("\n\t\t5. Add a new university\n");
  printf("\n\t\t6. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}

void add_node(node**phead,node*ToAdd){
  //
  //Adding at the beginning
  //
  if (*phead==NULL)
  {
    *phead=ToAdd;
  }else
  {
    ToAdd->next=*phead;
    *phead=ToAdd;
    ToAdd->next->previous=ToAdd;
  }
  
  
}

void traverse_LL(node*head){
   //local declarations
   node *walker=head;
   while (walker!=NULL)
   {
        printf("\n---------------------------");
        printf("\nName: %s",walker->name);
        printf("\nCity: %s",walker->city);
        printf("\nRanking: %d",walker->ranking);
        walker=walker->next;
   }
   
}

int delete_node(node**head,char*Todelete)
{
  //local declarations
  node *walker,*temp;
  if (*head==NULL)
  {
    return 0;
  }else if (strcmp(Todelete,(*head)->name)==0)
  {
    temp=*head;
    *head=(*head)->next;
    free(temp);
    if (*head!=NULL)
    {
        (*head)->previous=NULL;
    }
    
    return 1;
  }else
  {
    walker=*head;
    while (walker->next!=NULL)
    {
      if (strcmp(Todelete,walker->next->name)==0)
      {
        temp=walker->next;
        walker->next=temp->next;
        if (walker->next!=NULL)
        {
          walker->next->previous=walker;
        }
        free(temp);
        return 1;
      }
      walker=walker->next;
    }
    
    
  }

  return 0;
}

node * createLL(FILE *infp)
{
  //local declarations
  node *head=NULL,*new_nd;
  char line[100];
  fseek(infp,0,0);
  while (!feof(infp))
  {
    new_nd=(node*)malloc(sizeof(node));
    fscanf(infp,"%d\n",&new_nd->ranking);
    fgets(new_nd->name,50,infp);
    fgets(new_nd->city,50,infp);
    fgets(line,100,infp);
    new_nd->next=NULL;
    new_nd->previous=NULL;
    add_node(&head,new_nd);
  }
  return head;
}

void add_LL(node **head)
{
  //local declarations
  node *walker,*new_nd;
  new_nd=(node*)malloc(sizeof(node));
  fflush(stdin);
  printf("\nEnter the name of the university: ");
  gets(new_nd->name);
  fflush(stdin);
  printf("\nEnter the city: ");
  gets(new_nd->city);
  fflush(stdin);
  printf("\nEnter the ranking: ");
  scanf("%d",&new_nd->ranking);
  fflush(stdin);
  new_nd->next=NULL;
  new_nd->previous=NULL;
  add_node(head,new_nd);

}

int update_rank(node **head,char *Toupdate, int new_rank)
{
  //local declarations
  node *walker,*temp;
  if (*head==NULL)
  {
    return 0;
  }else if (strcmp(Toupdate,(*head)->name)==0)
  {
    temp=*head;
    temp->ranking=new_rank;
    *head=(*head)->next;
    delete_node(head,temp->name);
    add_node(head,temp);
    return 1;
  } 
  return 0;
}