#include "common.h"

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (root==NULL) {
            vector<vector<int> > retMatrix;
            return retMatrix;
        }
        // create TreeNode* matrix
        vector<vector<TreeNode*> > nodeMatrix;
        vector<TreeNode*> firstLayer;
        firstLayer.push_back(root);
        nodeMatrix.push_back(firstLayer);
        vector<TreeNode*> cur_layer = firstLayer;
        bool hasChild = (root->left!=NULL)||(root->right!=NULL);
        while(hasChild) {
            vector<TreeNode*> next_layer;
            for (vector<TreeNode*>::iterator it = cur_layer.begin(); it!=cur_layer.end(); ++it) {
                if ((*it)->left!=NULL)
                    next_layer.push_back((*it)->left);
                if ((*it)->right!=NULL)
                    next_layer.push_back((*it)->right);
            }
            hasChild = next_layer.size()!=0;
            if (hasChild) {
                nodeMatrix.push_back(next_layer);
                cur_layer = next_layer;
            }
        }
        // create result martix
        vector<vector<int> > retMatrix;
        for (int i=nodeMatrix.size()-1; i>=0; i--) {
            vector<int> int_layer;
            for (int j=0; j<nodeMatrix[i].size(); j++) {
                int_layer.push_back(nodeMatrix[i][j]->val);
            }
            retMatrix.push_back(int_layer);
        }
        return retMatrix;
    }
};

int main() {
    return 0;
}
