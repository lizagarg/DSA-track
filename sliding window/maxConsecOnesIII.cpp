class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int zeros=0;
        int n= nums.size();
        
        while(r<n) {
            if(nums[r]==0) zeros++;
            if(zeros>k) {
                while(zeros>k) {
                    if(nums[l]==0) zeros--;
                    l++;
                }
            }
            maxi= max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};