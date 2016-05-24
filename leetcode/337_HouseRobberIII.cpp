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
    int rob(TreeNode* root) {
        if (root==NULL)
            return 0;
        if ((root->left==NULL)&&(root->right==NULL))
            return root->val;
        else {
            int second = 0;
            int third = 0;
            if (root->left!=NULL) {
                second+=rob(root->left);
                third+=rob(root->left->left);
                third+=rob(root->left->right);
            }
            if (root->right!=NULL) {
                second+=rob(root->right);
                third+=rob(root->right->left);
                third+=rob(root->right->right);
            }
            if ((root->val+third)>second)
                return root->val+third;
            else
                return second;
        }
    }
};
