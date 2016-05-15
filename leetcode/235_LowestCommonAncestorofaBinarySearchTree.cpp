#include "common.h"

class Solution {
public:
    vector<TreeNode*> findPath(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> ret;
        if (root==NULL)
            return ret;
        // match, so return
        if (p->val==root->val) {
            ret.push_back(root);
            return ret;
        }
        // left search
        if (p->val<root->val) {
            vector<TreeNode*> leftRet = findPath(p->left, p);
            if (leftRet.size()>0)
                leftRet.push_back(root);
            return leftRet;
        }
        // right search
        if (p->val>root->val){
            vector<TreeNode*> rightRet = findPath(p->right, p);
            if (rightRet.size()>0)
                rightRet.push_back(root);
            return rightRet;
        }
        return ret;
    }
    vector<TreeNode*> findPath(TreeNode* root, int val) {
        vector<TreeNode*> ret;
        if (root==NULL)
            return ret;
        // match, so return
        if (val==root->val) {
            ret.push_back(root);
            return ret;
        }
        // left search
        if (val<root->val) {
            vector<TreeNode*> leftRet = findPath(root->left, val);
            if (leftRet.size()>0)
                leftRet.push_back(root);
            return leftRet;
        }
        // right search
        if (val>root->val){
            vector<TreeNode*> rightRet = findPath(root->right, val);
            if (rightRet.size()>0)
                rightRet.push_back(root);
            return rightRet;
        }
        return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        if (root==NULL||p==NULL|q==NULL)
            return NULL;
        if (p==q)
            return p;
        vector<TreeNode*> pPath = findPath(root, p);
        vector<TreeNode*> qPath = findPath(root, q);
        int pci = pPath.size()-1;
        int qci = pPath.size()-1;
        TreeNode* pcp = pPath[pci];
        TreeNode* qcp = pPath[qci];
        TreeNode* cap = pcp;
        while(pcp==qcp&&pci>0&&qci>0) {
            cap = pcp;
            pcp = pPath[--pci];
            qcp = qPath[--qci];
        }
        if (pcp==qcp)
            cap = pcp;
        return cap;*/
        if(root==NULL || p==NULL || q==NULL)
            return NULL;
        if(max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else
            return root;
    }
};

int UnitTest1() {
    int vals[] = {4, 2, 6, 1, 3, 5, 7};
    TreeNode* root = createTreeFromArray(vals, 7);
    Solution s;
    vector<TreeNode*> firstPath = s.findPath(root, 5);
    for (int i=firstPath.size()-1; i>=0; i--)
        cout<<firstPath[i]->val<<" - > ";
    cout<<endl;
    vector<TreeNode*> secondPath = s.findPath(root, 7);
    for (int i=secondPath.size()-1; i>=0; i--)
        cout<<secondPath[i]->val<<" - > ";
    cout<<endl;
    return 0;
}

int main()
{
    UnitTest1();
    //Solution s;
    //TreeNode* root = s.lowestCommonAncestor(vals, 7);
    //cout<<root->val<<", "<<root->left->val<<", "<<root->right->val<<endl;
    return 0;
}
