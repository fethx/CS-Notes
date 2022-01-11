// 234. Palindrome Linked List

// 1.Using auxiliary array.
// Time complexity: O(n)
// Space complexcity: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> aux;
        ListNode* cur = head;
        while(cur) {
            aux.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0;
        int r = aux.size() - 1;
        while(l < r) {
           if(aux[l] != aux[r])
                return false;
            l++;
            r--; 
        }
        return true;    
    }
};

// 2. Using slow and fast pointers to find the middle node,
// then reverse the second part, and compare if equal.
// T:O(n), S: O(1)
// This solution is similar to lc143.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        ListNode* pre = nullptr;
        slow->next = nullptr;
        while(second) {
            ListNode* next = second->next;
            second->next = pre;
            pre = second;
            second = next;
        }
        second = pre;
        ListNode* first = head;
        while(second) {
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
