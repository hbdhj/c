/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
