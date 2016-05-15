/**
 * Definition for a binary tree node.
 */
#include "common.h"

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if ((left==NULL)&&(right==NULL))
            return true;
        if (((left==NULL)&&(right!=NULL))||((right==NULL)&&(left!=NULL)))
            return false;
        if (left->val!=right->val)
            return false;
        return isMirror(left->left, right->right)&&isMirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL)
            return true;
        if ((root->left==NULL)&&(root->right==NULL))
            return true;
        if (((root->left==NULL)&&(root->right!=NULL))||((root->right==NULL)&&(root->left!=NULL)))
            return false;
        return isMirror(root->left, root->right);
    }
};

int main()
{
    return 0;
}
