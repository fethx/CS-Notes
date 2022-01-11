// 92. Reverse Linked List II

// 1. recursive
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1) {
            return reverseN(head, right);
        }
        head -> next = reverseBetween(head -> next, left - 1, right - 1);
        return head;
    }
private:
    ListNode* reverseN(ListNode* head, int n) {
        if(n == 1) {
            successor = head -> next;
            return head;
        }
        ListNode* last = reverseN(head -> next, n - 1);
        head -> next -> next = head;
        head -> next = successor;
        return last;
    }
private:
    ListNode* successor = NULL;
};

// solution 2. iterative
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {  
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for(int i = 0; i < right - left; ++i) {
            ListNode* next = cur->next;
            cur->next = next->next; 
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};
