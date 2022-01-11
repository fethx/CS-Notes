//86. Partition List

//1.In-place solution
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        while(head != NULL && head->val < x) {
            pre = head;
            head = head->next;
        }
        while(head != NULL && head->next != NULL) {
            if(head->next->val < x) {
                ListNode* tmp = head->next;
                head->next = tmp->next;
                //intsert
                tmp->next = pre->next;
                pre->next = tmp;
                pre = tmp;
                cout<<pre->val<<endl;
            } else {
                // If head->next move front, then continue check head->next, don't move head.
                head = head->next;
            }          
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

// 2. Creat two another linked list, one for smaller node, one for bigger node.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode* l = &left;
        ListNode* r = &right;        
        while(head != NULL) {  
            ListNode* & ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;
            head = head->next;
        } 
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};