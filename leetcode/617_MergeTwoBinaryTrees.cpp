class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1!=nullptr&&t2!=nullptr) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        } else if (t1==nullptr&&t2!=nullptr) {
            return t2;
        } else if (t1!=nullptr&&t2==nullptr) {
            return t1;
        } else {
            return nullptr;
        }
    }
};