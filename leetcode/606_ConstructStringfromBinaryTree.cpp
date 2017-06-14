class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t) {
            string ret = to_string(t->val);
            if (t->left || t->right) {
                ret += "(";
                if (t->left)
                    ret += tree2str(t->left);
                ret += ")";
                if (t->right) {
                    ret += "(";
                    ret += tree2str(t->right);
                    ret += ")";
                }
            }
            return ret;
        } else {
            return "";
        }
    }
};