/*

Copyright 2017 <Deng Haijun>

Data Structures > Trees >  Tree: Level Order Traversal


Sample Input

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  

Sample Output

1 2 5 3 6 4

*/

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct node {
    int data;
    node* left;
    node* right;
};

void levelOrder(node * root) {
    queue<node*> nodeQueue;
    if (root)
        nodeQueue.push(root);
    while (nodeQueue.size()) {
        node* toCheck = nodeQueue.front();
        if (toCheck) {
            cout << toCheck->data << " ";
            if (toCheck->left)
                nodeQueue.push(toCheck->left);
            if (toCheck->right)
                nodeQueue.push(toCheck->right);
        }
        nodeQueue.pop();
    }
}


int main() {
    const int treeSize = 6;
    vector<node*> treeNodes(treeSize, NULL);
    for (int i =0; i < treeSize; i++) {
        treeNodes[i] = new node();
        treeNodes[i]->left = NULL;
        treeNodes[i]->right = NULL;
    }
    treeNodes[0]->data = 1;
    treeNodes[0]->right = treeNodes[1];
    treeNodes[1]->data = 2;
    treeNodes[1]->right = treeNodes[2];
    treeNodes[2]->data = 5;
    treeNodes[2]->left = treeNodes[3];
    treeNodes[2]->right = treeNodes[4];
    treeNodes[3]->data = 3;
    treeNodes[3]->right = treeNodes[5];
    treeNodes[4]->data = 6;
    treeNodes[5]->data = 4;

    levelOrder(treeNodes[0]);

    for (int i =0; i < treeSize; i++) {
        delete treeNodes[i];
    }
    return 0;
}
