// solution 1, recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        dfs(root, postorder);
        return postorder;
    }
private:
    void dfs(TreeNode* root, vector<int> &postorder) {
        if(!root) return;
        if(root->left) dfs(root->left, postorder);
        if(root->right) dfs(root->right, postorder);
        postorder.push_back(root->val);
    }
};

// solution 2, iterative use stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        deque<int> postorder;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* tmp = root;
        while(!s.empty()) {
            tmp = s.top();
            s.pop();
            postorder.push_front(tmp->val); // reverse
            if(tmp->left)  s.push(tmp->left);
            if(tmp->right) s.push(tmp->right);
        }
        return vector<int>(postorder.begin(), postorder.end());
    }
};
