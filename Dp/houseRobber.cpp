class Solution {
public:
    ///space optimization
     int rob(vector<int>& nums) {
        int size =nums.size();
        int prev= nums[0];
        int prev2=0;
        for(int i=1;i<size;i++) {
            int take= nums[i];
            if(i>1) take+=prev2;
            int nottake= prev;
            int curr= max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
     }
};

class Solution {
public:
    //tabulatiom
     int rob(vector<int>& nums) {
        int size =nums.size();
        vector<int>dp(nums.size(),-1);
        dp[0]= nums[0];
        int neg=0;
        for(int i=1;i<size;i++) {
            int take= nums[i];
            if(i>1) take+=dp[i-2];
            int nottake= dp[i-1];
            dp[i]= max(take,nottake);
        }
        return dp[nums.size()-1];
     }
};

class Solution {
public:
    int solve(int i,int size,vector<int>& nums,vector<int>&dp){
        if(i<0) return 0;
        if (dp[i] != -1)  return dp[i];

        int inc = nums[i]+solve(i-2,size,nums,dp);
        int exl = solve(i-1,size,nums,dp);
        
        return dp[i]=max(inc,exl);
     }

     int rob(vector<int>& nums) {
        int size =nums.size();
        vector<int>dp(nums.size(),-1);
        return solve(nums.size()-1,size,nums,dp);
     }
};