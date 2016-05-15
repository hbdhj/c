#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* createListFromArray(int* arr, int len) {
    if (sizeof(arr)==0)
        return NULL;
    ListNode* head = NULL;
    for (int i = len - 1; i>=0; i--) {
        ListNode* pNode = new ListNode(arr[i]);
        pNode->next = head;
        head = pNode;
    }
    return head;
};

void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp!=NULL) {
        cout << tmp->val;
        if (tmp->next)
            cout<<" -> ";
        tmp = tmp->next;
    }
    cout<<endl;
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
