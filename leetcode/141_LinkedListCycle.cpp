/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *step1=head;
        ListNode *step2=head;
        while(step2!=NULL) {
            if (step2->next!=NULL) {
                step2=step2->next->next;
                step1=step1->next;
            } else {
                step2 = step2->next;
            }
            if (step1==step2)
                return true;
        }
        return false;
    }
};
