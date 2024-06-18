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
  int choice,f_info=0; 
  char ToDelete[30]; 
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
      printf("\nNOt yet");
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
  //local declarations
  node *walker;
  if (*phead==NULL)
  {
    *phead=ToAdd;
  }else if (ToAdd->ranking<(*phead)->ranking)
  {
    ToAdd->next=*phead;
    (*phead)->previous=ToAdd;
    *phead=ToAdd;
  }else
  {
    walker=*phead;
    while (walker->next!=NULL)
    {
        if (ToAdd->ranking<walker->next->ranking)
        {
            ToAdd->next=walker->next;
            ToAdd->previous=walker;
            walker->next=ToAdd;
            ToAdd->next->previous=ToAdd;
            break;
        }
        walker=walker->next;
    }
    if (walker->next==NULL)
    {
        walker->next=ToAdd;
        ToAdd->previous=walker;
    }
    
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
    (*head)->previous=NULL;
    free(temp);
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
          temp->next->previous=walker;
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
    (*head)->ranking=new_rank;
    temp=*head;
    
  }
  
 
}