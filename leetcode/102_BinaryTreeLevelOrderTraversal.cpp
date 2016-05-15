/**
 * Definition for a binary tree node.
 */
#include "common.h"

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<TreeNode*> list;
        vector<vector<int> > ret;
        if (root==NULL)
            return ret;
        list.push_back(root);
        vector<int> first_level(1, root->val);
        ret.push_back(first_level);
        int start = 0;
        bool gotChild = (list[start]->left!=NULL)||(list[start]->right!=NULL);
        while (gotChild) {
            gotChild = false;
            int end = list.size();
            vector<int> level;
            for (int i = start; i<end; i++) {
                if (list[i]->left!=NULL) {
                    list.push_back(list[i]->left);
                    level.push_back(list[i]->left->val);
                }

                if (list[i]->right!=NULL) {
                    list.push_back(list[i]->right);
                    level.push_back(list[i]->right->val);
                }
            }
            if (level.size()>0)
                ret.push_back(level);
            gotChild = list.size()>end;
            start = end;
        }
        return ret;
    }
};

int main()
{
    int vals[] = {1, 2, 3};
    TreeNode* root = createTreeFromArray(vals, 3);
    cout<<root->val<<", "<<root->left->val<<", "<<root->right->val<<endl;
    Solution s;
    s.levelOrder(root);
    return 0;
}
