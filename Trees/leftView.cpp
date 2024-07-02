void helper(Node* root, int level, vector<int> &ans) {
    if(root == nullptr) return;
    if(level == ans.size()) ans.push_back(root->data);
    helper(root->left, level + 1, ans);
    helper(root->right, level + 1, ans);
}

// Function to return a list containing elements of the left view of the binary tree.
vector<int> leftView(Node *root) {
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}