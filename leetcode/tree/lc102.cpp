// solution 1, bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
private:
    vector<vector<int>> bfs(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while(!cur.empty()) {
            res.push_back({});
            for(TreeNode* node : cur) {
                res.back().push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            cur.clear();
            cur.swap(next);
        }
        return res;
    }
};

// solution 1, dfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> preorder;
        dfs(root, 0, preorder);
        return preorder;
    }
private:
    void dfs(TreeNode* root, int level, vector<vector<int>> &preorder) {
        if(!root) return;
        while(preorder.size() <= level) preorder.push_back({});
        preorder[level].push_back(root->val);
        dfs(root->left, level + 1, preorder);
        dfs(root->right, level + 1, preorder);
    }

};

