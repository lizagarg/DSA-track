class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int tens=0;
        for(int i=0; i<bills.size(); i++) {
            if(bills[i]==5) five++;
            else if(bills[i]==10) {
                if(five<1) return false;
                else{
                    tens++;
                    five--;
                }
            } else {
                if(tens>=1 and five>=1){
                    tens--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};