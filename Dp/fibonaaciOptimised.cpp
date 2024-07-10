class Solution {
public:
    int fib(int n) {
        //optimizing sc
        if(n==0) return 0;
        int a=0;
        int b=1;
      
        for(int i=2; i<=n; i++) {
            int c= a+b;
            a=b;
            b=c;
        }

        return b;
    }
};