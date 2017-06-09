/*

Copyright 2017 <Deng Haijun>

Data Structures > Trees > Tree: Postorder Traversal 

*/

/* you only have to complete the function given below.  
Node is defined as  


*/

#include "./common.h"

struct node
{
    int data;
    node* left;
    node* right;
};

void postOrder(node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    return 0;
}