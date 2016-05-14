#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *former = dummy;
        ListNode *check = head;
        while(check != NULL) {
            if(check->val == val) {
                former->next = check->next;
                delete(check);
            } else {
                former = former->next;
            }
            check = former->next;
        }
        return dummy->next;
    }
};

ListNode* createTreeFromArray(int* arr, int len) {
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

void printTree(ListNode* head) {
    ListNode* tmp = head;
    while (tmp!=NULL) {
        cout << tmp->val;
        if (tmp->next)
            cout<<" -> ";
        tmp = tmp->next;
    }
    cout<<endl;
};

int UnitTest1() {
    Solution s;
    int vals[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* root = createTreeFromArray(vals, 7);
    printTree(root);
    s.removeElements(root, 6);
    printTree(root);
    return 0;
};

int UnitTest2() {
    Solution s;
    int vals[] = {1};
    ListNode* root = createTreeFromArray(vals, 1);
    printTree(root);
    s.removeElements(root, 1);
    printTree(root);
    return 0;
};

int main()
{
    //UnitTest1();
    UnitTest2();
    return 0;
}
