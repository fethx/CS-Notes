//83. Remove Duplicates from Sorted List

// 1. recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val) {
            ListNode* del = head->next;
            head->next = del->next;
            delete del;
        }
        return head;
    }
};

// 2. iterative
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL) {
            if(cur->val == cur->next->val) {
                ListNode* del = cur->next;
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
}; 