#include "common.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    int vals[] = {1, 2, 3};
    TreeNode* root = createTreeFromArray(vals, 3);
    cout<<root->val<<", "<<root->left->val<<", "<<root->right->val<<endl;
    Solution s;
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
