#include "common.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};

int main() {
    return 0;
}
