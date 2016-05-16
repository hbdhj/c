#include "common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // no node
        if (head==NULL)
            return head;
        if (head->next==NULL)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* newHead = second;
        ListNode* tail = first;
        while (second) {
            // now swap
            first->next = second->next;
            second->next = first;
            tail = first; // tail is the second now
            // move forward
            second = first->next; // second is the next first
            if (second) {
                first=second;
                second=first->next;
                if (second) {
                    tail->next = second; // tail -> set to the first
                } else {
                    tail->next = first; // tail -> set to the first
                }
            } else {
                break;
            }
        }
        return newHead;
    }
};

int UT0() {
    Solution s;
    int vals0[] = {};
    ListNode* head0 = createListFromArray(vals0, 0);
    printList(head0);
    ListNode* ret0 = s.swapPairs(head0);
    printList(ret0);
    return 0;
}

int UT1() {
    Solution s;
    int vals1[] = {1};
    ListNode* head1 = createListFromArray(vals1, 1);
    printList(head1);
    ListNode* ret1 = s.swapPairs(head1);
    printList(ret1);
    return 0;
}

int UT2() {
    Solution s;
    int vals2[] = {1, 2};
    ListNode* head2 = createListFromArray(vals2, 2);
    printList(head2);
    ListNode* ret2 = s.swapPairs(head2);
    printList(ret2);
    return 0;
}

int UT3() {
    Solution s;
    int vals3[] = {1, 2, 3};
    ListNode* head3 = createListFromArray(vals3, 3);
    printList(head3);
    ListNode* ret3 = s.swapPairs(head3);
    printList(ret3);
    return 0;
}

int UT4() {
    Solution s;

    int vals4[] = {1, 2, 3, 4};
    ListNode* head4 = createListFromArray(vals4, 4);
    printList(head4);
    ListNode* ret4 = s.swapPairs(head4);
    printList(ret4);
    return 0;
}

int main() {
    UT0();
    UT1();
    UT2();
    UT3();
    UT4();

    return 0;
}
