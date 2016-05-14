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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return false;
        return hasLeafPathSum(root, sum);
    }
    bool hasLeafPathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return sum==0;
        if ((root->left==NULL)&&(root->right==NULL))
            return root->val==sum;
        if ((root->left!=NULL)&&(root->right==NULL))
            return hasLeafPathSum(root->left, sum-(root->val));
        if ((root->left==NULL)&&(root->right!=NULL))
            return hasLeafPathSum(root->right, sum-(root->val));
        if ((root->left!=NULL)&&(root->right!=NULL))
            return hasLeafPathSum(root->left, sum-(root->val))||hasLeafPathSum(root->right, sum-(root->val));
        return false;
    }
};
