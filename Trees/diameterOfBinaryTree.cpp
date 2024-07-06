class Solution {
public:
    int helper(TreeNode* root, int &maxi) {
        if(root==NULL) return 0;

        int l= helper(root->left,maxi );
        int r= helper(root->right, maxi);
        maxi= max(maxi, l+r);
        return 1+ max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        helper(root, maxi);
        return maxi;
    }
};