//24. Swap Nodes in Pairs

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while(p->next != NULL && p->next->next != NULL) {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            
            p = node1;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};