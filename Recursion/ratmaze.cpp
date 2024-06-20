class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>&a,int n, vector<string> &ans, string move, vector<vector<int>>&vis,int di[], int dj[]){
        //base case
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return;
        }
       
       string direction = "DLRU";
        for (int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];

            // Check boundaries and whether the next cell is visitable
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            // Mark the next as visited
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + direction[index], vis, di, dj);
                // Unmark the cell
                vis[i][j] = 0;
            }
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,1,0};
        if(m[0][0]==1) solve(0,0,m,n,ans,"",vis,di,dj);
        return ans;
    }
};