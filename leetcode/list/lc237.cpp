// 237. Delete Node in a Linked List

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;
        if(node->next == nullptr) {
            delete node;
            node = nullptr;
        } else {
            node->val = node->next->val;
            ListNode* delNode = node->next;
            node->next = delNode->next;
            delete delNode;
        }
    }
};