class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        dfs(root, postorder);
        return postorder;
    }
private:
    void dfs(Node* root, vector<int> &preorder) {
        if(!root) return;
        for(Node* node : root->children)
            dfs(node, preorder);
        preorder.push_back(root->val);
    }
};