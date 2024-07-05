class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size()) return *max_element(arr.begin(), arr.end());
        if(k==1) return max(arr[0],arr[1]);
        int count=0;
        int winner=arr[0];
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]<winner) count+=1;
            else {
                winner=arr[i];
                count=1;
            }

            if(k==count) return winner;
        }
        return winner;
    }
};