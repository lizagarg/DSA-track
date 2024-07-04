class Solution {
  public:
  
    void helper(Node* root, vector<int>&path, vector<vector<int>>&ans) {
        if (root == NULL)
        return;
        
        path.push_back(root->data);
       
        if (root->left == NULL && root->right == NULL) 
        ans.push_back(path);
        
        helper(root->left, path, ans);
        helper(root->right, path, ans);
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<int>path;
        vector<vector<int>> ans;
        helper(root, path, ans);
        return ans;
    }
};