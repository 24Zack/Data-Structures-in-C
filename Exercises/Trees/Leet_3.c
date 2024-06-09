#include <stdio.h>
#include <stdlib.h>
/**
 * Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes 
along the longest path from the root node down to the farthest leaf node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// int maxDepth(struct TreeNode* root) 
// {
//     if (root==NULL)
//     {
//         return -1;
//     }else
//     {
//         int height_left=(1+maxDepth(root->left));
//         int height_right=(1+maxDepth(root->right));
//         if (height_left<height_right)
//         {
//             return height_right;
//         }else
//         {
//             return height_left;
//         }   
//     }

// }
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    int max = (leftMax > rightMax) ? leftMax : rightMax;
    return 1 + max;
}