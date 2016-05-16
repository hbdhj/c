/**
 * Definition for a binary tree node.
 */
#include "common.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root) {
            char buf[40];
            snprintf ( buf, 40, "%d", root->val );
            string valStr = buf;
            if (root->left) {
                vector<string> leftRet = binaryTreePaths(root->left);
                for (int i=0; i<leftRet.size(); i++)
                    ret.push_back(valStr+"->"+leftRet[i]);
            }
            if (root->right) {
                vector<string> rightRet = binaryTreePaths(root->right);
                for (int i=0; i<rightRet.size(); i++)
                    ret.push_back(valStr+"->"+rightRet[i]);
            }
            if ((root->left==NULL)&&(root->right==NULL))
                ret.push_back(valStr);
        }
        return ret;
    }
};

int main()
{
    int vals[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = createTreeFromArray(vals, 7);
    Solution s;
    vector<string> ret = s.binaryTreePaths(root);
    for (int i=0; i<ret.size(); i++)
        cout<<ret[i]<<endl;
    return 0;
}
