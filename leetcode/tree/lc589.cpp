class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        dfs(root, preorder);
        return preorder;
    }
private:
    void dfs(Node* root, vector<int> &preorder) {
        if(!root) return;
        preorder.push_back(root->val);
        for(Node* node : root->children)
            dfs(node, preorder);
    }
};