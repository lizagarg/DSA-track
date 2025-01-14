class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n= s.length();
        int len=0;
        int maxi=INT_MIN;
        if(s.length()==0) return 0;
        unordered_map<char,int>mp;
        while(r<n) {
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l) {
                l=mp[s[r]]+1;
            }
            len=r-l+1;
            maxi=max(maxi,len);
            mp[s[r]]=r;
            r++;
        }
        return maxi;
    }
};