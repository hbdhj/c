/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<TreeNode*> list;
        vector<vector<int> > ret;
        if (root==NULL)
            return ret;
        list.push_back(root);
        vector<int> first_level(1, root->val);
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

TreeNode* createTreeFromArray(int* arr, int len) {
    if (sizeof(arr)==0)
        return NULL;
    TreeNode** tree = new TreeNode*[len];
    TreeNode* root = new TreeNode(arr[0]);
    tree[0] = root;
    for (int i = 1; i<len; i++) {
        if (arr[i]!='#')
            tree[i] = new TreeNode(arr[i]);
        if (i%2) {
            tree[(i-1)/2]->left = tree[i];
        } else {
            tree[i/2-1]->right = tree[i];
        }
    }
    return root;
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
