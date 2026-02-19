class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        bool neg=false;

        if(x<0){
            neg=true;
            x=-x;
        }

        while(x>0){
            int lastdgt=x%10;
            
            if(rev>INT_MAX/10 or (rev==INT_MAX/10 and lastdgt>7)){
                return 0;
            }

            if(rev<INT_MIN/10 or (rev==INT_MIN/10 and lastdgt<-8)){
                return 0;
            }

            rev = rev*10+lastdgt;
            x/=10;
        } 

        return neg ? -rev : rev;
    }
};