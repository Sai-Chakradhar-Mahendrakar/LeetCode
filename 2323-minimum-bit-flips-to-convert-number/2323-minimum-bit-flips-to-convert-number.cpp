class Solution {
public:
    int minBitFlips(int start, int goal) {
        int differentBits = start^goal;
        return countSetBits(differentBits);
    }
private:
    int countSetBits(int n){
        int ans=0;
        while(n>0){
            ans++;
            n=n&(n-1);
        }
        return ans;
    }
};