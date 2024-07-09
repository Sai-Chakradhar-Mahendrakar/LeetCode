class Solution {
public:
    vector<int> memo;
    int dp(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(memo[n]!=-1){
            return memo[n];
        }

        return memo[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
    }
    int tribonacci(int n) {
        memo.resize(n+1, -1);
        return dp(n);
    }
};