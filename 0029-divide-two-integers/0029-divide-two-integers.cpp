class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        int sign=1;
        if(dividend>0 && divisor<0){
            sign=-1;
        }
        if(dividend<0 && divisor>0){
            sign=-1;
        }

        unsigned int n=abs(dividend);
        unsigned int d=abs(divisor);
        unsigned int ans=0;
        while(n>=d){
            int cnt=0;
            while(n>(d<<(cnt+1))){
                cnt++;
            }
            n-=(d<<cnt);
            ans+=(1<<cnt);
        }

        if(ans==(1<<31) && sign==1){
            return INT_MAX;
        }

        return sign*ans;
    }
};