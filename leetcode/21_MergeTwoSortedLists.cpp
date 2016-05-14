#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        if (l1->val>l2->val) {
            head = l2;
            tail = l2;
            l2 = l2->next;
        }
        else {
            head = l1;
            tail = l1;
            l1 = l1->next;
        }
        cout<<"head->val = "<<head->val<<", tail->val = "<<tail->val<<endl;
        while (l1!=NULL&&l2!=NULL) {
            if (l1->val>l2->val) {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            } else {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        cout<<"head->val = "<<head->val<<", tail->val = "<<tail->val<<endl;
        while (l1!=NULL) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        cout<<"head->val = "<<head->val<<", tail->val = "<<tail->val<<endl;
        while (l2!=NULL) {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
        cout<<"head->val = "<<head->val<<", tail->val = "<<tail->val<<endl;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    cout<<s.mergeTwoLists(l1, l2)<<endl;

    return 0;
}
