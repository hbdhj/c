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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start = head;
        while(start!=NULL) {
            while ((start->next!=NULL)&&(start->val)==(start->next->val)) {
                // remove the same value node
                ListNode* toRemove = start->next;
                start->next=toRemove->next;
                delete toRemove;
            }
            start=start->next;
        }
        return head;
    }
};
