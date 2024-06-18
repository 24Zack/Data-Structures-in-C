#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nd{
  char name[50]; 
  char city[30];
  int ranking; 
  struct nd*next;
}node;

void menu(void); 
void traverse_LL(node*);
void add_node(node**,node*);
int delete_node(node**head, char*ToDelete);
void create_LL(FILE *, node **);
int update_ranking(node **,char *, int);
//Homework: Define a function that will be used
//to update the ranking of a university

/*         Main Function        */
int main(void){
  int choice; 
  char ToDelete[30]; 
  node*head=NULL,*new_node;
  int status;  
  FILE *infp;
  infp=fopen("input.txt","r");
  if (infp==NULL)
  {
    printf("\nThe file doesn t exist in the directory");
    return 1;
  }
   do{

      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:
      
		       break;
	    case 2:

		       break;
	    case 3:
      traverse_LL(head);
		       break;
	    case 4:
      
		       break;
      case 5:     
               break;
      case 6:
      printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");

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
  printf("\n\t\t1. Create a linked list\n");
  printf("\n\t\t2. Delete a Node from a LL\n");
  printf("\n\t\t3. Traverse a LL\n");
  printf("\n\t\t4. Update a university ranking\n");
  printf("\n\t\t5. Add a node to the LL\n");
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
    *phead=ToAdd;
  }else
  {
    walker=*phead;
  }
  
  
  
}

void traverse_LL(node*head){
   node*walker=head; 
   if(head==NULL)
     printf("\n\t\tLinked list is EMPTY!\n");
   else{	    
     while(walker!=NULL){
       printf("\n\t\tUniversity Name:%s\n",walker->name);
       printf("\n\t\tLocated in:%s\n",walker->city);
       printf("\n\t\tRanking:%d\n",walker->ranking);
       printf("\n\t\t-------------------\n");
       walker=walker->next;   
      }
   }
}
int delete_node(node**head, char*ToDelete)
{
  //local declarations
  node *walker,*temp;
  if (strcmp(ToDelete,(*head)->name)==0)
  {
    temp=*head;
    *head=(*head)->next;
    free(temp);
    return 1;
  }else
  {
    walker=*head;
    while (walker->next!=NULL)
    {
      if (strcmp(ToDelete,walker->next->name)==0)
      {
        temp=walker->next;
        walker->next=temp->next;
        free(temp);
        return 1;
      }
      walker=walker->next;
    }
    
  }
  
  
  return 0;
}

void create_LL(FILE *infp, node **head)
{
  //local declaratiosn
  char line[100];
  node *new_nd;
  while (!feof(infp))
  {
    new_nd=(node*)malloc(sizeof(node));
    fscanf(infp,"%d\n",&new_nd->ranking);
    fgets(new_nd->name,50,infp);
    fgets(new_nd->city,30,infp);
    fgets(line,100,infp);
    add_node(head,new_nd);
  }
  
}

int update_ranking(node **head,char *Toupdate, int new_rank)
{
  //local declarations

}