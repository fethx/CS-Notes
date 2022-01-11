//2. Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(sum || l1 || l2) {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            sum /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy.next;
    }
};