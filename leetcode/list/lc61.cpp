//61. Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        // (len-k)node->next == nullptr;
        for(int i = 1; i < len-k; ++i)
            head = head->next;
        tail->next = dummy.next;
        dummy.next = head->next;
        head->next = nullptr;
        return dummy.next;
    }
};
