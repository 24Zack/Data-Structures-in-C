#include<stdio.h>
#include<stdlib.h>
typedef struct nd{
  char name[20];
  int id; 
  struct nd* next;
}node;

int main(void){
  node*head=NULL,*new_node,*walker;
  char answer;
      
      printf("\n\t\tTime to create a LL!\n");
      
	do{   
 	 new_node= (node*)malloc(sizeof(node));
     printf("\n\t\tInput the student name:");
	 gets(new_node->name);
	 printf("\n\t\tInput %s's ID:",new_node->name);
	 scanf("%d",&new_node->id);
	 new_node->next=NULL;
	 if(head==NULL)
	   head=new_node;
     else{
	   walker=head; 
	   while(walker->next!=NULL)
	     walker=walker->next;
       //Outside the loop
         walker->next=new_node;
	   }
	 printf("\n\t\t--> %s was added to LL!\n",new_node->name);  
	 printf("\n\t\tDo you want to add another node? Y/N:");
	 scanf(" %c",&answer);//enter
	 getchar();   
	}while(answer!='n'&& answer!='N');

   // Let's traverse the LL    
   walker=head; 
     printf("\n\t\t--------------\n");
     printf("\n\t\tThis is the content of your LL:\n");
	 while(walker!=NULL){
       printf("\n\t\t%s\t%d->\n",walker->name,walker->id);	 
       walker=walker->next;
	 }
	 printf("\n\t\t");
return 0;
}
