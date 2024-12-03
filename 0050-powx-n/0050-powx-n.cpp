class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long long N = n;
        while(N<0){
            x = 1/x;
            N = -N;
        }
        double res=1;
        while(N){
            if(N&1){
                res*=x;
            }
            x*=x;
            N/=2;
        }
        return res;
    }
};