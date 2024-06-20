// /* Change this code by:
// 1. Adding a menu option that compute the height of a tree
// 2. Change for duplicates, add a counter.
// */
#include <stdio.h>
#include <stdlib.h>

typedef struct tag{
   int N;
   struct tag*left;
   struct tag*right;
   int count;
}node;

//Function prototypes
void menu(void);
node* create_node(int N);
int search_element(node*root,int N);
node* add_node(node*root,node*ToAdd);
node* create_initial_BST(FILE*infp,node*root);
void traverse_inOrder(node*root);
node* find_min(node*root);
node* delete_node(node*root,int toDelete);
int compute_height_tree(node *root);
int traverse_right(node *root);
int traverse_left(node *root);

int main(void)
{
  FILE*infp;
  int choice,N,status;
  node* root=NULL, *new_node;
  int i,height;

  infp= fopen("data.txt","r");
  if(infp==NULL)
    {
    	printf("\n\t\tSORRY! Could not open the file!\n\t\tProgram will end!\n\t\t");
    	return(0);
	}
   else{
   root=create_initial_BST(infp,root);
   do{
    menu();
    scanf("%d",&choice);
    switch(choice){
    case 1:

          break;
    case 2:

          break;
    case 3:

          break;
    case 4:

          break;
    case 5:
      //  Compute the height of the tree
      height= compute_height_tree(root);
      printf("\n\t\tHeight of the tree is %d",height);

            break;
    case 6: printf("\n\t\tDecided to QUIT....\n\n\t\tBYE\n\n\t\t");
            break;
    default: printf("\n\t\tWRONG CHOICE!!\n");
   }
   }while(choice!=6);
   }
   fclose(infp);
return(0);
}


//  Function definition

void menu(void)
{

    printf("\n\t\t----------- Let's Practice BST ------------\n");
    printf("\n\t\t1. Add a new node\n");
    printf("\n\t\t2. Search if a node Exists\n");
    printf("\n\t\t3. Delete a node\n");
    printf("\n\t\t4. Traverse the Tree InOrder\n");
    printf("\n\t\t5. Compute the height of the tree\n");
    printf("\n\t\t6. QUIT\n");
    printf("\n\t\t--------------------------------------------\n");
    printf("\n\t\tYour choice:");
}

node* create_node(int N)
{

}

int search_element(node*root,int N)
{

}
node* add_node(node*root,node*ToAdd){

}

node* create_initial_BST(FILE*infp,node*root){


}

void traverse_inOrder(node*root){


}
node* find_min(node*root){


}

node* delete_node(node*root,int toDelete)
{

}

int compute_height_tree(node *root)
{


}
