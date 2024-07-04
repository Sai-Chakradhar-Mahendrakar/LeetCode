class Solution {
public:
    // dp[idx]=min(dp[idx+1],dp[idx+2])+cost[idx]
    vector<int> memo;
    int dp(vector<int>& cost, int idx){
        if(idx>=cost.size()){
            return 0;
        }

        if(memo[idx]!=-1){
            return memo[idx];
        }

        int takeOneStep = dp(cost,idx+1);
        int takeTwoSteps = dp(cost,idx+2);

        return memo[idx]=min(takeOneStep,takeTwoSteps)+cost[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size()+1,-1);
        return min(dp(cost,0),dp(cost,1));
    }
};