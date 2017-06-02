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

struct node {
    int data;
    node* left;
    node* right;
};

void print_left(node *root) {
    if (root) {
        print_left(root->left);
        cout << root->data << " ";
    }
}

void print_right(node *root) {
    if (root) {
        cout << root->data << " ";
        print_right(root->right);
    }
}

void top_view(node * root) {
    if (root) {
        if (root->left)
            print_left(root->left);
        cout << root->data << " ";
        if (root->right)
            print_right(root->right);
    }
}

int main() {
    vector<node*> treeNodes(9, NULL);
    for (int i =0; i < 9; i++) {
        treeNodes[i] = new node();
    }
    treeNodes[0]->data = 3;
    treeNodes[0]->left = treeNodes[1];
    treeNodes[0]->right = treeNodes[2];
    treeNodes[1]->data = 5;
    treeNodes[1]->left = treeNodes[3];
    treeNodes[1]->right = treeNodes[4];
    treeNodes[2]->data = 2;
    treeNodes[2]->left = treeNodes[5];
    treeNodes[2]->right = treeNodes[6];
    treeNodes[3]->data = 1;
    treeNodes[3]->right = treeNodes[7];
    treeNodes[4]->data = 4;
    treeNodes[5]->data = 6;
    treeNodes[6]->data = 7;
    treeNodes[6]->left = treeNodes[8];
    treeNodes[7]->data = 9;
    treeNodes[8]->data = 8;

    top_view(treeNodes[0]);

    for (int i =0; i < 9; i++) {
        delete treeNodes[i];
    }
    return 0;
}
