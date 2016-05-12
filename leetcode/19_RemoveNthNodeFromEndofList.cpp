struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode *p1 = head, *p2 = head;
        int i=0;
        while(i<n)
            p2 = p2->next, i++;
        if(p2 == NULL)
            return head->next;
        while(p2->next)
            p1 = p1->next, p2=p2->next;
        p1->next = p1->next->next;
        return head;
    }
};
