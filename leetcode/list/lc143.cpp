143. Reorder List	

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Separate list, the slow node is the last node of the first part.
        ListNode* second = slow->next;
        ListNode* pre = nullptr;
        slow->next = nullptr;
        // Reverse the second part.
        while(second) {
            ListNode* next = second->next;
            second->next = pre;
            pre = second;
            second = next;
        }
        //Now pre is the head of the second part.
        second = pre;
        ListNode* first = head;
        while(second) {
            ListNode* l1 = first->next;
            ListNode* l2 = second->next;
            first->next = second;
            second->next = l1;
            first = l1;
            second = l2;
        }
        return;
    }
};
