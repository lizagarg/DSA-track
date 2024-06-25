class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int>res(n,-1);
        stack<int>st;

        for(int i=2*n-1; i>=0; i--) {
            //pop out smaller elements
            while(!st.empty() && nums[i%n]>= st.top()) {
                st.pop();
            }

            //array needed only for first half
            if(i<n && !st.empty()) {
                res[i]=st.top();
            } 

            st.push(nums[i%n]);
        }
        return res;
    }
};