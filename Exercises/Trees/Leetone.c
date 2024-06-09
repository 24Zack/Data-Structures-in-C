/**
 * You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val 
and return the subtree rooted with that node. 
If such a node does not exist, return null.
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root==NULL)
    {
        return NULL;
    }else if (root->val==val)
    {
        return root;
    }
    else
    {
        root->left=searchBST(root->left,val);
        root->right=searchBST(root->right,val);
        
    }
    if (root->left==NULL && root->right==NULL)
    {
        return NULL;
    }
    
}