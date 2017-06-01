/*

Copyright 2017 <Deng Haijun>

Data Structures > Trees > Tree: Inorder  Traversal 

*/

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void inOrder(node *root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
