//19. Remove Nth Node From End of List
//Double pointers

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        ListNode* q = &dummy;
        for(int i = 0; i < n + 1; ++i)
            q = q->next;
        while(q) {
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        
        return dummy.next;
    }
};