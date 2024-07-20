class Solution {
private:
     int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid) {
        //base case
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int up= grid[i][j]+ f(i-1,j,dp, grid);
        int left= grid[i][j]+ f(i,j-1,dp, grid);

        return dp[i][j]= min(left,up);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};

class Solution {
    //tabulation
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) dp[0][0]= grid[0][0];
                else {
                    int up=1e9;
                    int left=1e9;
                    if(i>0)  up= grid[i][j]+ dp[i-1][j];
                    if(j>0)  left= grid[i][j]+ dp[i][j-1];
                    dp[i][j]= min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};