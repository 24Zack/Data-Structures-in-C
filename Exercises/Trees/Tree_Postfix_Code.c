#include <stdio.h>
#include <stdlib.h> 

typedef struct tag{
  struct tag *left;
  struct tag *right;
  char ch;
}treeNode;

typedef struct tag1{
  struct tag1 *next;
  treeNode *data;
}Stack_node;


void traverse_preOrder(treeNode*root){
  if(root==NULL)
    return;
  else{
    printf("%c",root->ch); 
    traverse_preOrder(root->left);
    traverse_preOrder(root->right); 
  }	
}
void traverse_InOrder(treeNode *root){
if(root==NULL)
    return;
  else{
    traverse_InOrder(root->left);
    printf("%c",root->ch);
    traverse_InOrder(root->right); 
  }	
}
 
void menu(void){
   printf("\n\t\t-------- Binary Tree From a Postfix Expression --------\n"); 
   printf("\n\t\t 1. Create the Binary Tree\n");
   printf("\n\t\t 2. Print Infix Expression (Traverse inOrder)\n");
   printf("\n\t\t 3. Print Prefix Expression (Traverse preOrder)\n");
   printf("\n\t\t 4. Quit\n");
   printf("\n\t\t Your choice please:");
}

treeNode * create_binary_tree(treeNode *root)
	
int main(void){

FILE*infp; 
int choice;
treeNode *root=NULL;

  infp=fopen("postfix.txt","r"); 
  if(infp==NULL)
    printf("\n\t\tCould not open the FILE!\n\t\t"); 
  else{
  	do{
    menu(); 
	scanf("%d",&choice);  
	switch(choice){
	
	case 1://Create the binary tree
	             
	       break;
    case 2:if(root==NULL)
             printf("\n\t\tTree is not contructed YET!\n");
           else{ 
	         printf("\n\t\t");
			 traverse_InOrder(root);
			 printf("\n");
			 }
		   break;
    case 3:
          if(root==NULL)
             printf("\n\t\tTree is not contructed YET!\n");
           else{
           printf("\n\t\t");	
	       traverse_preOrder(root);
           printf("\n");
		   }
	       break;
    case 4: printf("\n\t\tTake Care!\n\n\t\t");
	        break; 
	default:printf("\n\t\tINVALID CHOICE!\n");
	}
	}while(choice!=4);
  }
  return 0;
}
