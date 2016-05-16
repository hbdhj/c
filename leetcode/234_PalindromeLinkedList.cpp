class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* mid = getMid(head);
        ListNode* head2 = reverse(mid);
        while(head && head2)
        {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    ListNode* getMid(ListNode* head)
    {// at least two nodes
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* preslow = NULL;
        do
        {
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
                preslow = slow;
                slow = slow->next;
            }
        }while(fast != NULL);
        preslow->next = NULL;
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        else if(head->next->next == NULL)
        {// two nodes
            ListNode* tail = head->next;
            head->next = NULL;
            tail->next = head;
            return tail;
        }
        else
        {
            ListNode* pre = head;
            ListNode* cur = pre->next;
            pre->next = NULL;   // set tail
            ListNode* post = cur->next;
            while(post)
            {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = post->next;
            }
            cur->next = pre;
            return cur;
        }
    }
};
