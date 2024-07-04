class Solution {
public:
    vector<int> memo;
    int dp(int n){
        if(n<=2){
            return n;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        return memo[n]=dp(n-1)+dp(n-2);
    }

    int climbStairs(int n) {
        memo.resize(n+1, -1);
        return dp(n);
    }
};