/*

Copyright 2017 <Deng Haijun>

Data Structures > Trees > Tree: Postorder Traversal 

Sample Input

2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output

1 4
1 2

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


void postOrder(node *root) {
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}