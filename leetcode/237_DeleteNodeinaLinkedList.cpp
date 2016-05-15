class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) {

        } else {
            ListNode* tmp = node->next;
            node->val = tmp->val;
            node->next = tmp->next;
            delete tmp;
        }
    }
};
