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
node* delete_node(node*,char*,int*);
node * create_LL(FILE *);

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
  }else
  {
      do{

      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:
      head=create_LL(infp);
		       break;
	    case 2:if(head==NULL)
	             printf("\n\t\tLinked List is EMPTY!\n");
               else{
			     getchar(); 
				 printf("\n\t\tInput the university name to delete:");
				 gets(ToDelete);
				 head=delete_node(head,ToDelete,&status);
				 if(status==0)
				   printf("\n\t\t%s was not found in the LL!\n",ToDelete);
			     else
				   printf("\n\t\t%s was deleted from the LL!\n",ToDelete);  
			   }
		       break;
	    case 3:traverse_LL(head);
		       break;
	    case 4:
      
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
node* delete_node(node*head, char*ToDelete,int*pstatus){
node*temp, *walker;
*pstatus=0; 
  if(strcmp(ToDelete,head->name)==0){
    temp=head; 
    head=head->next;
    free(temp);
    *pstatus=1;  
  }
  else{
    walker=head; 
    while(walker->next!=NULL){
	  if(strcmp(ToDelete,walker->next->name)==0){
	    temp=walker->next;
	    walker->next= temp->next;
	    free(temp);
	    *pstatus=1;
	    break;  
	  }
	  else
	    walker=walker->next;
	 }
    }
 return(head);
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