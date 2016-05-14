/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;
        int left_highth = highth(root->left);
        int right_highth = highth(root->right);
        int diff = left_highth>right_highth?(left_highth-right_highth):(right_highth-left_highth);
        if (diff>1)
            return false;
        return (isBalanced(root->left))&&(isBalanced(root->right));
    }
    int highth(TreeNode* root) {
        if (root==NULL)
            return 0;
        return max(highth(root->left), highth(root->right))+1;
    }
};
