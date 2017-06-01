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

struct node
{
    int data;
    node* left;
    node* right;
};

*/


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

