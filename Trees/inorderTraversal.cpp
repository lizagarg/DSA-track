class Solution {
    void traversal(TreeNode* root, vector<int>&ans) {
        if (root == nullptr) return;
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        traversal(root,ans);
        return ans;
    }
};