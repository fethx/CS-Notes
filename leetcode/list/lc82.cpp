//82. Remove Duplicates from Sorted List II

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        while(head != NULL) {
            while(head->next != NULL && head->val == head->next->val) {
                ListNode* del = head;
                head = del->next;
                delete del;
            }
            // Head not move, meanings no duplicate occur in current cycle.
            if(pre->next == head)
                pre = head;
            else
                pre->next = head->next;
            head = head->next;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};