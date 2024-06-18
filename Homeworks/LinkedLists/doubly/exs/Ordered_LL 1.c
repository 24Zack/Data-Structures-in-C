#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nd{
  char name[30]; 
  char city[30];
  int ranking; 
  struct nd*next;
  struct nd*previous;
}node;

void menu(void); 
void traverse_LL(node*);
node* create_fill_node(void); 
void add_node(node**,node*);
node* delete_node(node*,char*,int*);
//Homework: Define a function that will be used
//to update the ranking of a university

/*         Main Function        */
int main(void){
  int choice; 
  char ToDelete[30]; 
  node*head=NULL,*new_node;
  int status;    
   do{

      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:new_node=create_fill_node();
	           add_node(&head,new_node);
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
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Add a new node to LL\n");
  printf("\n\t\t2. Delete a Node from a LL\n");
  printf("\n\t\t3. Traverse a LL\n");
  printf("\n\t\t4. Update a university ranking\n");
  printf("\n\t\t5. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}
node* create_fill_node(void){
  node*new_node; 
  
  new_node = (node*)malloc(sizeof(node));
  getchar(); 
  printf("\n\t\tInput university name:"); 
  gets(new_node->name); 
  printf("\n\t\tInput %s's city:",new_node->name); 
  gets(new_node->city);
  printf("\n\t\tInput %s's ranking:",new_node->name); 
  scanf("%d",&new_node->ranking);
  new_node->next=NULL;
  return(new_node);
}
void add_node(node**phead,node*ToAdd){
  node*walker; 
  if(*phead==NULL)
    *phead=ToAdd; 
  else{
    walker=*phead; 
    while(walker->next!=NULL){
	  walker=walker->next;
	}
	walker->next=ToAdd;  
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
