/**
 * Given the root of a binary tree, return the inorder traversal of its nodes' values
*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    if (root==NULL)
    {
        return;
    }else
    {
        inorderTraversal(root->left,&returnSize);
        printf("%d",root->val);

        inorderTraversal(root->right,&returnSize);
    }

}