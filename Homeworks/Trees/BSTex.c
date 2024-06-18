/* Change this code by:
// 1. Adding a menu option that compute the height of a tree
2. Allow duplicates by adding a counter to each node.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct tag{
   int N;
   struct tag*left;
   struct tag*right;
   int count;
}node;

void menu(void){

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
 node*new_node;
 new_node= (node*)malloc(sizeof(node));
 new_node->N=N;
 new_node->left=NULL;
 new_node->right=NULL;
 new_node->count=1;
 return(new_node);
}

int search_element(node*root,int N)
{
  if(root==NULL)
    return(0);
  else if (root->N ==N)
    return(1);
  else if(N<root->N)
    return(search_element(root->left,N));
  else
   return(search_element(root->right,N));
}

node* add_node(node*root,node*ToAdd){

 if(root==NULL)
 {
   root=ToAdd;
 }else if (root->N==ToAdd->N)
 {
  root->count++;
 }else if(ToAdd->N < root->N)
 {
   root->left= add_node(root->left,ToAdd);
 }else
 {
   root->right= add_node(root->right,ToAdd);
 }
return(root);
}

node* create_initial_BST(FILE*infp,node*root){

   node* new_node;
   int N,x;

   fseek(infp,0,0);
   while(!feof(infp))
   {
    fscanf(infp,"%d",&N);
    new_node=create_node(N);
    root=add_node(root,new_node);
    }
  return(root);
}

void traverse_inOrder(node*root){

  if(root==NULL)
    return;
  else{
  traverse_inOrder(root->left);
	for (int i = 0; i < root->count; i++)
  {
    printf("\t%d ", root->N);
  }

	traverse_inOrder(root->right);
  }
}

node* find_min(node*root)
{

   if(root->left==NULL)
     return(root);
   else
     return(find_min(root->left));
}

void delete_node(node**root,int toDelete)
{
  //local declarations
  node *temp;
  if (root==NULL)
  {
    return;
  }else if ((*root)->N<toDelete)
  {
   delete_node((*root)->right,toDelete);
  }else if ((*root)->N>toDelete)
  {
    delete_node((*root)->left,toDelete);
  }else if ((*root)->left!=NULL && (*root)->right!=NULL)
  {
    temp=find_min((*root)->right);
    (*root)->N=temp->N;
    delete_node((*root)->right,(*root)->N);
  }else
  {
    temp=root;
    if ((*root)->left==NULL)
    {
      (*root)=(*root)->right;
    }else if ((*root)->right==NULL)
    {
      root=(*root)->left;
    }
    free(temp);

  }
}

int compute_height(node *root)
{
  if (root==NULL)
  {
    return -1;
  }else
  {
    int height_left= compute_height(root->left);
    int height_right= compute_height(root->right);
    if (height_left>height_right)
    {
      return height_left+1;
    }else
    {
      return height_right+1;
    }
  }

}

int main(void)
{
  //declarations
  FILE*infp;
  int choice,N,status;
  node* root=NULL, *new_node;
  int i,height_of_tree;

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
          printf("\n\t\tInput the value of N:");
          scanf("%d",&N);
        new_node=create_node(N);
		  	root=add_node(root,new_node);
		  	printf("\n\t\t%d was added to the BST!\n",N);

          break;
    case 2:printf("\n\t\tInput a number to search for:");
	       scanf("%d",&N);
		   status=search_element(root,N);
		   if(status==0)
		     printf("\n\t\t%d was not found in the BST!\n",N);
		   else
		     printf("\n\t\t%d was found in the BST!\n",N);
          break;
    case 3:printf("\n\t\tPlease input the number to delete:");
           scanf("%d",&N);
           status=search_element(root, N);
           if(status==0)
             printf("\n\t\t%d was NOT FOUND in the BST!\n",N);
           else{
		       delete_node(root,N);
               printf("\n\t\t%d was deleted from the BST!\n",N);
               }
          break;
    case 4:if(root==NULL)
             printf("\n\t\tBST is EMPTY!\n");
		   else{
	         printf("\n\t\t Your BST has the following numbers:\n\t");
             traverse_inOrder(root);
             printf("\n");
		   }
      break;
    case 5:
        height_of_tree=compute_height(root);
        printf("\nThe height of the tree is %d",height_of_tree);
            break;
    case 6: printf("\n\t\tDecided to QUIT....\n\n\t\tBYE\n\n\t\t");
            break;
    default: printf("\n\t\tWRONG CHOICE!!\n");
   }
   }while(choice!=6);
   }
return(0);
}
