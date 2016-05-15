/**
 * Definition for a binary tree node.
 */
#include "common.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p==NULL)&&(q==NULL))
            return true;
        if (((p!=NULL)&&(q==NULL))|| ((p==NULL)&&(q!=NULL)))
            return false;
        if (p->val!=q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    int vals[] = {1, 2, 3};
    TreeNode* root = createTreeFromArray(vals, 3);
    cout<<root->val<<", "<<root->left->val<<", "<<root->right->val<<endl;
    return 0;
}
