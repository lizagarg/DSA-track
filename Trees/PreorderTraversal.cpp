class Solution {
     void traversal(TreeNode* root, vector<int>&ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        traversal(root,ans);
        return ans;
    }
};