class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> preorder;
        dfs(root, 0, preorder);
        return preorder;
    }
private:
    void dfs(Node* root, int level, vector<vector<int>> &preorder) {
        if(!root) return;
        while(preorder.size() <= level) preorder.push_back({});
        preorder[level].push_back(root->val);
        for(Node* node : root->children)
            dfs(node, level + 1, preorder);
    }
};