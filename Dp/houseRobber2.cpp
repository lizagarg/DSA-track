class Solution {
public:
      int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int inc = nums[i] + solve(i - 2, nums, dp);
        int exl = solve(i - 1, nums, dp);

        return dp[i] = max(inc, exl);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++) {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int max1 = solve(temp1.size() - 1, temp1, dp1);
        int max2 = solve(temp2.size() - 1, temp2, dp2);

        return max(max1, max2);
    }
};