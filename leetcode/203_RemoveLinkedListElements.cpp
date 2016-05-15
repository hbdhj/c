#include "common.h"

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

int UnitTest1() {
    Solution s;
    int vals[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* root = createListFromArray(vals, 7);
    printList(root);
    s.removeElements(root, 6);
    printList(root);
    return 0;
};

int UnitTest2() {
    Solution s;
    int vals[] = {1};
    ListNode* root = createListFromArray(vals, 1);
    printList(root);
    s.removeElements(root, 1);
    printList(root);
    return 0;
};

int main()
{
    //UnitTest1();
    UnitTest2();
    return 0;
}
