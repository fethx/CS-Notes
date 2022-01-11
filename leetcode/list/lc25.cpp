//25. Reverse Nodes in k-Group

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPre = dummy;
        ListNode* groupNext = head;
        ListNode* kth = head;
        
        while(true) {
            kth = getKth(groupPre, k);
            if(kth == NULL)
                break;
            groupNext = kth->next;
            //reverse group
            ListNode* pre = groupNext; // Connect current and next group. 
            ListNode* cur = groupPre->next;        
            while(cur != groupNext) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ListNode* tmp = groupPre->next;
            // Connect previous and current group. 
            groupPre->next = kth;
            groupPre = tmp;
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
    }
    ListNode* getKth(ListNode* curr, int k) {
        while(curr != NULL && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
