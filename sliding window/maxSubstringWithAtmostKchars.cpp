class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0;
        int maxi=0;
        unordered_map<int,int>mp;
        int n= fruits.size();

        while(r<n) {
            mp[fruits[r]]++;
            if(mp.size()>2) {
                while(mp.size()>k) {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};