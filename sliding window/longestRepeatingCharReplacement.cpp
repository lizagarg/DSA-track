class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int maxlen=0, maxf=0;
        unordered_map<char, int> mp;
        int n= s.length();

        while(r<n) {
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);

            while((r-l+1)-maxf > k) {
                mp[s[l]]--;
                l++;
            }
            maxlen= max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};