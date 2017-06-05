/*

Copyright 2017 <Deng Haijun>

Data Structures > Trees >  Tree : Top View 


Sample Input

     3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8

Sample Output

1 5 3 2 7


*/

/* you only have to complete the function given below.  
Node is defined as  
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST(node *root) {
    if (root) {
        if (root->left)
            if (root->left->data>=root->data)
                return false;
        if (root->right)
            if (root->right->data<=root->data)
                return false;
        return checkBST(root->left) && checkBST(root->right);
    }
    return true;
}

int main() {
    vector<node*> treeNodes(7, NULL);
    for (int i =0; i < 7; i++) {
        treeNodes[i] = new node();
    }
    treeNodes[0]->data = 4;
    treeNodes[0]->left = treeNodes[1];
    treeNodes[0]->right = treeNodes[2];
    treeNodes[1]->data = 2;
    treeNodes[1]->left = treeNodes[3];
    treeNodes[1]->right = treeNodes[4];
    treeNodes[2]->data = 6;
    treeNodes[2]->left = treeNodes[5];
    treeNodes[2]->right = treeNodes[6];
    treeNodes[3]->data = 1;
    treeNodes[4]->data = 3;
    treeNodes[5]->data = 5;
    treeNodes[6]->data = 7;

    if(checkBST(treeNodes[0])) {
        cout << "Yes" <<endl;
    } else {
        cout << "No" <<endl;
    }

    for (int i =0; i < 7; i++) {
        delete treeNodes[i];
    }
    return 0;
}
