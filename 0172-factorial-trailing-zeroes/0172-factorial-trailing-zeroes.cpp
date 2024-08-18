class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        while(n>=5){
            cnt+=(n/5);
            n/=5;
        }
        return cnt;
    }
};