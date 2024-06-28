class Solution {
    void traversal(TreeNode* root, vector<int>&ans) {
        if (root == nullptr) return;
        traversal(root->left, ans);
        traversal(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        traversal(root,ans);
        return ans;
    }
};