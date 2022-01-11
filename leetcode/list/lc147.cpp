//147. Insertion Sort List
// O(n^2)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;
            if(next != NULL && next->val < cur->val) {
                while(pre->next != NULL && pre->next->val < next->val) {
                    pre = pre->next;
                }
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                // Reset pre.
                pre = dummy;
            } else {
                cur = next;
            }
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
    }
};
