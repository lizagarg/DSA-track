class Solution {
public:
    int check(TreeNode* root) {
        if(!root) return 0;

        int l = check(root->left);
        if (l == -1) return -1; // If left subtree is not balanced

        int r = check(root->right);
        if (r == -1) return -1; // If right subtree is not balanced

        if (abs(r - l) > 1) return -1; // If current node is not balanced

        return 1 + max(l, r); // Return height if balanced
    }
    bool isBalanced(TreeNode* root) {
       return check(root) !=-1;
    }
};