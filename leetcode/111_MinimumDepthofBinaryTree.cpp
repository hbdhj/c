/**
 * Definition for a binary tree node.
 */
#include "common.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        if ((root->left==NULL)&&(root->right==NULL))
            return 1;
        if ((root->left!=NULL)&&(root->right!=NULL)) {
            int minLeft = minDepth(root->left);
            int minRight = minDepth(root->right);
            int min = minLeft<minRight?minLeft:minRight;
            return min + 1;
        }
        if ((root->left==NULL)&&(root->right!=NULL)) {
            return minDepth(root->right)+1;
        }
        if ((root->left!=NULL)&&(root->right==NULL)) {
            return minDepth(root->left)+1;
        }
        return 0;
    }
};

int main()
{
    int vals[] = {1, 2, 3};
    TreeNode* root = createTreeFromArray(vals, 3);
    cout<<root->val<<", "<<root->left->val<<", "<<root->right->val<<endl;
    return 0;
}
