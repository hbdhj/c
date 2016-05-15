#include "common.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLinkLength(headA);
        int lenB = getLinkLength(headB);
        ListNode* pA = headA;
        ListNode* pB = headB;
        if (lenA>lenB) {
            pA = listWalk(headA, lenA - lenB);
        }
        if (lenB>lenA) {
            pB = listWalk(headB, lenB - lenA);
        }
        while((pA!=pB)&&(pA!=NULL)&&(pB!=NULL)) {
            pA=pA->next;
            pB=pB->next;
        }
        if ((pA==NULL)||(pB=NULL))
            return NULL;
        return pA;
    }
};

int main() {
    return 0;
}
