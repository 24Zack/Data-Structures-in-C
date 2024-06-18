#include <stdio.h>
#include <stdlib.h> 

//Tree structure
typedef struct tag{
  char value;
  struct tag*left;
  struct tag*right;
}treeNode;

//Stack structure
typedef struct tag2{
  treeNode *tree_node_address;
  struct tag2 *next;
}stack_node;

//  Function prototypes
treeNode * create_tree_node(char ch);
stack_node* create_stack_node(treeNode *X);
void push(stack_node**top,stack_node*topush);
treeNode* pop(stack_node**top);
void traverse_preOrder(treeNode*root);
void traverse_InOrder(treeNode* root);
void menu(void);
void create_binary_tree(FILE *infp,treeNode**root);

int main(void){
  //declarations
  FILE*infp; 
  int choice;
  treeNode *root=NULL;
  int f_info=0;

  infp=fopen("postfix.txt","r"); 
  if(infp==NULL)
  {
    printf("\n\t\tCould not open the FILE!\n\t\t"); 
  }else
  {

  do{
  menu(); 
	scanf("%d",&choice);  
	switch(choice){
	
	case 1:
    //Create the binary tree
    if (f_info==0)
    {
     create_binary_tree(infp,&root);  
     f_info=1;
    }else
    {
      printf("\nYou already created the binary tree!");
    }
    
	       break;
    case 2:
    if(root==NULL)
    {
      printf("\n\t\tTree is not contructed YET!\n");
    }else
    { 
	    printf("\n\t\t");
			traverse_InOrder(root);
			printf("\n");
		}
		   break;
    case 3:
    if(root==NULL)
    {
      printf("\n\t\tTree is not contructed YET!\n");
    }else
    {
      printf("\n\t\t");	
	    traverse_preOrder(root);  
      printf("\n");
		}
	      break;
    case 4: 
    printf("\n\t\tTake Care!\n\n\t\t");
	        break; 
	default:
    printf("\n\t\tINVALID CHOICE!\n");
    break;
	}
	}while(choice!=4);
  }

  return 0;
}


//    Function definitions

treeNode* create_tree_node(char ch)
{
  treeNode* new_node=(treeNode*)malloc(sizeof(treeNode));
  new_node->value=ch;
  new_node->left=NULL;
  new_node->right=NULL;
  return new_node;
}
stack_node *create_stack_node(treeNode *X)
{
  stack_node*new_node;
  new_node=(stack_node*)malloc(sizeof(stack_node));
  new_node->tree_node_address=X;
  new_node->next=NULL;
  return new_node;
}
void push(stack_node**top,stack_node*topush)
{
  if (*top==NULL)
  {
    *top=topush;
  }else
  {
    topush->next=*top;
    *top=topush;
  }
}

treeNode* pop(stack_node**top)
{
  stack_node *temp;
  treeNode *content;

  if (*top==NULL)
  {
    return NULL;
  }else
  {
    temp=*top;
    *top=temp->next;
    content=temp->tree_node_address;
    free(temp);
    return content;
  }
}

void traverse_preOrder(treeNode*root)
{
  if(root==NULL)
    return;
  else{
    printf("%c",root->value); 
    traverse_preOrder(root->left);
    traverse_preOrder(root->right); 
  }	
}

void traverse_InOrder(treeNode* root)
{
if(root==NULL){
    return;
}else
{
  traverse_InOrder(root->left);
  printf("%c",root->value);
  traverse_InOrder(root->right); 
}	
}
 
void menu(void)
{
   printf("\n\t\t-------- Binary Tree From a Postfix Expression --------\n"); 
   printf("\n\t\t 1. Create the Binary Tree\n");
   printf("\n\t\t 2. Print Infix Expression (Traverse inOrder)\n");
   printf("\n\t\t 3. Print Prefix Expression (Traverse preOrder)\n");
   printf("\n\t\t 4. Quit\n");
   printf("\n\t\t Your choice please:");
}

// void create_binary_tree(FILE *infp,treeNode**root)
// {
//   //local declarations
//   char ch_f;
//   treeNode *new_tree_node;
//   stack_node*top=NULL;
//   stack_node*new_stack_node;

//   //    This works
//   // do
//   // {
//   //   ch_f=getc(infp);
//   //   if (ch_f==EOF)
//   //   {
//   //     break;
//   //   }
//   //   new_tree_node=create_tree_node(ch_f);
//   //   if (ch_f=='+'||ch_f=='/'||ch_f=='*'||ch_f=='-')
//   //   {
//   //     new_tree_node->right=pop(&top);
//   //     new_tree_node->left=pop(&top);

//   //   }
//   //   //regardless if ch_f is an operator or an opreand,
//   //   //the node address should be pushed to the stack
//   //   new_stack_node=create_stack_node(new_tree_node);
//   //   push(&top,new_stack_node);
    
//   // } while (ch_f!=EOF);


//   while (!feof(infp))
//   {
//     ch_f=getc(infp);
//     if (ch_f==EOF)
//     {
//       break;
//     }
//     new_tree_node=create_tree_node(ch_f);
//     if (ch_f=='+'||ch_f=='/'||ch_f=='*'||ch_f=='-')
//     {
//       new_tree_node->right=pop(&top);
//       new_tree_node->left=pop(&top);

//     }
//     //regardless if ch_f is an operator or an operand,
//     //the node address should be pushed to the stack
//     new_stack_node=create_stack_node(new_tree_node);
//     push(&top,new_stack_node);
    
//   }
  
//   //pop everything and save it into the root
//   *root=pop(&top);

// }

void create_binary_tree(FILE *infp,treeNode**root)
{
  //local declarations
  stack_node*top=NULL,*new;
  treeNode*new_nd;
  char ch_s;

  fseek(infp,0,0);
  while (!feof(infp))
  {
    fscanf(infp,"%c",&ch_s);
    if (ch_s==EOF)
    {
      break;
    }else
    {
      new_nd=(treeNode*)malloc(sizeof(treeNode));
      new_nd->left=NULL;
      new_nd->right=NULL;
      new_nd->value=ch_s;
      if (ch_s=='+'||ch_s=='-'||ch_s=='/'||ch_s=='*')
      {
        new_nd->right=pop(top);
        new_nd->left=pop(top);
      }
      new=(stack_node*)malloc(sizeof(stack_node));
      new->next=NULL;
      new->tree_node_address=new_nd;
      push(&top,new);

      
    }
    

    
  }
  
  
}
