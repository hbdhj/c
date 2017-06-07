/*

Copyright 2017 <Deng Haijun>

Tutorials > Cracking the Coding Interview > Linked Lists: Detect a Cycle 

*/

#include "./common.h"

bool has_cycle(Node* head) {
    if (head) {
        Node* step2 = head->next;
        Node* step1 = head;
        while (step2) {
            if (step1 == step2)
                return true;
            if (step2->next)
                step2 = step2->next->next;
            else
                step2 = step2->next;
            step1 = step1->next;
        }
        return false;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
