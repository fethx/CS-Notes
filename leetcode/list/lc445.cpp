//445. Add Two Numbers II

// 1. First reverse the input lists and then use the Add Two Numbers solution, at last reverse the result.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseListRecursive(l1);
        ListNode* rl2 = reverseListRecursive(l2);
        ListNode* sumList = addTwoNumbersOne(rl1, rl2);
        return reverseListRecursive(sumList);
    }
private:    
    ListNode* reverseListRecursive(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode* last = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* addTwoNumbersOne(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode sumList(0);
        ListNode* sumHead = &sumList;
        while(sum || l1 || l2) {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            sumHead->next = new ListNode(sum%10);
            sumHead = sumHead->next;
            sum /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return sumList.next;
    }
};

// 2. Use stack without reversing.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1 != NULL) {
            s1.push(l1->val);
            ListNode* del = l1;
            l1 = del->next;
            delete del;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            ListNode* del = l2;
            l2 = l2->next;
            delete del;
        }
        return addTwoNumbersOne(s1, s2);
    }
private:    
    ListNode* addTwoNumbersOne(stack<int> s1, stack<int> s2) {
        int sum = 0;
        ListNode* reverseHead = NULL;
        while(sum || !s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            ListNode* tmp = new ListNode(sum%10);
            tmp->next = reverseHead;
            reverseHead = tmp;
            sum /= 10;
        }
        return reverseHead;
    }
};
