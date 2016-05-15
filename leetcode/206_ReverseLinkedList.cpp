#include "common.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head!=NULL) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = newHead;
            newHead = tmp;
        }
        return newHead;
    }
};

int main() {
    return 0;
}
