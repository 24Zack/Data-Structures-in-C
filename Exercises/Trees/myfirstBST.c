/**
 * BST - binary search tree
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct nd{
    int N;
    struct nd *left;
    struct nd*right;
    //int count; --> not mandatory
}node;
//  Prototypes
// node * Add(node *root, node *toAdd);
void Add(node **root, node *toAdd);
int search(node *root, int N);
node* delete_node(node *root, int toDelete);
node* find_min(node * root);
int main(void)
{
    //declarations
    node *new_nd;
    new_nd=(node*)malloc(sizeof(node));
    new_nd->N=10;
    
    return 0;
}

// node * Add(node *root, node *toAdd)
// {
//     if (root==NULL)
//     {
//         root=toAdd;
//     }else if (toAdd->N>root->N)
//     {
//         root->right=Add(root->right,toAdd);
//     }else
//     {
//         root->left=Add(root->left,toAdd);
//     }
//     return root;
// }

void Add(node **root, node *toAdd)
{
    if (*root==NULL)
    {
        *root=toAdd;
    }else if ((*root)->N<toAdd->N)
    {
        Add((*root)->right,toAdd);
    }else
    {
        Add((*root)->left,toAdd);
    }
    
}

int search(node *root, int N)
{
    if (root==NULL)
    {
        return 0;
    }else if (root->N==N)
    {
        return 1;
    }else if (root->N<N)
    {
        search(root->left,N);
    }else
    {
        search(root->right,N);
    }  
}

node* delete_node(node *root, int toDelete)
{
    //local declarations
    node *temp;
    if (root==NULL)
    {
        return root;
    }else if (toDelete<root->N)
    {
        root->left=delete_node(root->left,toDelete);
    }else if (toDelete>root->N)
    {
        root->right=delete_node(root->right,toDelete);
    }else if (root->left!=NULL && root->right!=NULL)
    {
        temp=find_min(root);
        root->N=temp->N;
        root->right=delete_node(root->right,root->N);
    }else
    {
        temp=root;
        //  Node is either a leaf or a node with 1 kid
        if (root->left==NULL)
        {
            root=root->right;
        }else if (root->right==NULL)
        {
            root=root->left;
            free(temp);
        }
        
        return root;
    }
    
}

node* find_min(node * root)
{
    if (root==NULL)
    {
        return root;
    }else
    {
        return(find_min(root->left));
    }
    
    
}