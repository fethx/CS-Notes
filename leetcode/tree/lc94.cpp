// solution 1, recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);
        return inorder;
    }
private:    
    void dfs(TreeNode* root, vector<int> &inorder) {
        if(!root) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};

// solution 2, iterative use stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp) {
            while(tmp) {
                s.push(tmp);
                tmp = tmp->left;
            }
            tmp = s.top();
            s.pop();    
            inorder.push_back(tmp->val);
            tmp = tmp->right;
        }
        return inorder;
    }
};
