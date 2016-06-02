class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==NULL)
            return 0;
        int cnt = 1;
        if (root->left!=NULL)
            cnt+=countNodes(root->left);
        if (root->right!=NULL)
            cnt+=countNodes(root->right);
        return cnt;
    }
};
