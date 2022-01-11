//328. Odd Even Linked List
//The solution is the same as lc86.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0), even(0);
        ListNode* oddHead = &odd;
        ListNode* evenHead = &even;
        int flag = 1;
        while(head != NULL) {
            ListNode* & ref = flag == 1 ? oddHead : evenHead;
            ref->next = head;
            ref = ref->next;
            head = head->next;
            flag *= -1;
        }
        oddHead->next = even.next;
        evenHead->next = NULL;
        return odd.next;
    }
};