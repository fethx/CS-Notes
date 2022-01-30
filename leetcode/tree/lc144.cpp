// solution 1, recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        dfs(root, preorder);
        return preorder;
    }
private:    
    void dfs(TreeNode* root, vector<int> &preorder) {
        if(!root) return;
        preorder.push_back(root->val);
        dfs(root->left, preorder);
        dfs(root->right, preorder);
    }
};

// solution 2, iterative use stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> preorder;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* tmp = root;
        while(!s.empty()) {
            tmp = s.top();
            s.pop();
            preorder.push_back(tmp->val);
            if(tmp->right) s.push(tmp->right);
            if(tmp->left)  s.push(tmp->left);
        }
        return preorder;
    }
};

