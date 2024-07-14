class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cookieIndex=0;
        int childIndex=0;
        int satisfied=0;
        while(cookieIndex<s.size() && childIndex<g.size()){
            if(g[childIndex]<=s[cookieIndex]){
                satisfied++;
                cookieIndex++;
                childIndex++;
            } else {
                //move to next cookie
                cookieIndex++;
            }
        }
        return satisfied;
    }
};