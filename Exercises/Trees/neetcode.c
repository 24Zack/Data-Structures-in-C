/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

// struct TreeNode *temp=*root;

bool isUnivalTree(struct TreeNode* root)
{
    if (root==NULL)
    {
        return true;
    }else if (root->val!=temp->val)
    {
        return false;
    }else
    {
        bool left= isUnivalTree(root->left);
        bool right=isUnivalTree(root->right);
        if (left==true && right==true)
        {
            return true;
        }else
        {
            return false;
        }
    }
}
int main(void)
{
    struct TreeNode *root;
}