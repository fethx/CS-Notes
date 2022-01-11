// 148. Sort List
// Linked list merge sort

// 1.Top-down (recursion)
// Time complexity: O(nlogn)
// Space complexity: O(logn)
// Using slow and fast pointers to find mid node
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0 or 1 element
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(mid));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};


// 2. Bottom-up
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0 or 1 element
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail;
        ListNode* l;
        ListNode* r;
        for(int n = 1; n < len; n += n) {
            tail = &dummy;
            ListNode* cur = dummy.next;
            while(cur) {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            } 
        }
        return dummy.next;
    }
private:
    // Return the head of the second part.
    ListNode* split(ListNode* head, int n) {
        while(--n && head)
            head = head->next;
        ListNode* rest = head ? head->next : nullptr;
        // Cut the first part.
        if(head)
            head->next = nullptr;
        return rest;
    }
    
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
};

