class Solution {
public:
    bool isMirror(TreeNode* lefttree, TreeNode* righttree) {
    if (!lefttree && !righttree) return true;
    if (!lefttree || !righttree) return false;
    return (lefttree->val == righttree->val)
    && isMirror(lefttree->left, righttree->right) 
    && isMirror(lefttree->right, righttree->left);
}

    bool isSymmetric(TreeNode* root) {
       if (!root) return true;
       return isMirror(root->left, root->right);
    }
};