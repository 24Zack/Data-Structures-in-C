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
int delete_node(node**,char*);
node * create_LL(FILE *);
int update_rank(node **,char *,int);

//Homework: Define a function that will be used
//to update the ranking of a university

/*         Main Function        */
int main(void){
  int choice; 
  char ToDelete[30],ToUpdate[40]; 
  node*head=NULL,*new_node;
  int status,new_rank;  
  FILE *infp;
  infp=fopen("input.txt","r");
  if (infp==NULL)
  {
    printf("\nThe file doesn t exist in the directory");
  }else
  {
      do{

      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:
      head=create_LL(infp);
		       break;
	    case 2:
      fflush(stdin);
      printf("\nEnter the name of the university: ");
      gets(ToDelete);
      fflush(stdin);
      if (delete_node(&head,ToDelete))
      {
        printf("\n%s was successfully deleted from the LL");
      }else
      {
        printf("\n%s was not deleted from the LL");
      }
		       break;
	    case 3:traverse_LL(head);
		       break;
	    case 4:
      fflush(stdin);
      printf("\nEnter the name of the university: ");
      gets(ToUpdate);

		       break;
	    case 5:printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
               break;
	    default:printf("\n\t\tThat was an INVALID CHOICE!\n");
	  }//end of switch
   }while(choice!=5);   
  }
  
  
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
  printf("\n\t\t5. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}


void add_node(node**phead,node*ToAdd){
  node*walker; 
  if(*phead==NULL)
    *phead=ToAdd; 
  else if (ToAdd->ranking<(*phead)->ranking)
  {
    ToAdd->next=*phead;
    *phead=ToAdd;

  }
  else
  {
    walker=*phead;
    while (walker->next!=NULL)
    {
      if (ToAdd->ranking<walker->next->ranking)
      {
        ToAdd->next=walker->next;
        walker->next=ToAdd;
        break;
      }else
      {
        walker=walker->next;
      }
    }
    if (walker->next==NULL)
    {
      walker->next=ToAdd;
    }

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
int delete_node(node**head, char*ToDelete){
node*temp, *walker;
  if (*head==NULL)
  {
   return 0; 
  }else if(strcmp(ToDelete,(*head)->name)==0){
    temp=head; 
    (*head)=(*head)->next;
    free(temp); 
    return 1;
  }else{
    walker=*head; 
    while(walker->next!=NULL){
	  if(strcmp(ToDelete,walker->next->name)==0){
	    temp=walker->next;
	    walker->next= temp->next;
	    free(temp);
        return 1;
	  }
	  else
	    walker=walker->next;
	 }
    }

    return 0;
}

node * create_LL(FILE *infp)
{
  //local declarations
  node *new_node;
  char line[50];
  node *head=NULL;
  while (!feof(infp))
  {
    new_node=(node*)malloc(sizeof(node));
    fscanf(infp,"%d\n",&new_node->ranking);
    fgets(new_node->name,50,infp);
    fgets(new_node->city,30,infp);
    fgets(line,50,infp);
    new_node->next=NULL;
    add_node(&head,new_node);
  }
  return head;
}

int update_rank(node **head,char *Toupdate, int new_ranking)
{
    //declarations
    node *walker,*temp;
    if (*head==NULL)
    {
        return 0;
    }else
    {
        walker=*head;
        while (walker!=NULL)
        {
            if (strcmp(Toupdate,walker->name)==0)
            {
                temp=walker;
                temp->ranking=new_ranking;
                delete_node(head,temp->name);
                add_node(head,temp->name);
                return 1;
            }
            walker=walker->next;
        }
        
    }
    return 0;
    
}
void sorting_LL(node *head)
{
    for (node* walker = head; walker->next!=NULL ; walker=walker->next){
        node *min=walker;
        for (node * walker2 = walker->next; walker2->next!=NULL; walker=walker->next)
        {
            if (strcmp(walker2->name,walker->name)>0)
            {
                min=walker2;
            }
            
        }
    if (min!=walker)
    {
        /**
         * Here we are swapping the content of the LL not the addresses 
         * so we will call swap but only to swap the name,rank AND that's it
        */
    }
    
        
    }
    
}