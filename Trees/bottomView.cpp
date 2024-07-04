class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        map<int,int>mpp;
        vector<int>ans;
        if(root==NULL) return ans;
        
        q.push({root,0});
        
        while(!q.empty()) {
            auto it= q.front();
            q.pop();
            Node* node= it.first;
            int line= it.second;
            
            mpp[line]= node->data;
            if(node->left!= NULL) 
            q.push({node->left,line-1 });
            
            if(node->right!= NULL) 
            q.push({node->right,line+1 });
        }
        
        for(auto i: mpp) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};