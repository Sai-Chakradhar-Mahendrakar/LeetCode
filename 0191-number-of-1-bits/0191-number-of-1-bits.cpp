class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n>0){
            n &= (n-1);
            ans++;
        }
        return ans;
    }
};