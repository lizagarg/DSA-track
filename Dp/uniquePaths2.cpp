class Solution {
private:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&obstacleGrid) {
        //base case
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!= -1) return dp[i][j];

        int up= f(i-1,j,dp, obstacleGrid);
        int left= f(i,j-1,dp, obstacleGrid);
        return dp[i][j]= left+up;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(m-1,n-1,dp,obstacleGrid);
    }
};


class Solution {
public:
   //tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));

        for(int i=0; i<m; i++) {
            for(int j=0;j< n; j++) {
               if(i>=0 && j>=0 && obstacleGrid[i][j]==1) dp[i][j]=0;
               else if (i == 0 && j == 0) dp[0][0]=1;
               else{
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i-1][j];
                    if (j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
               }     
            }
        }
        return dp[m-1][n-1];
    }
};