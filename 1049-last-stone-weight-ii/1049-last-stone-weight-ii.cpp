class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(int i : stones) total+=i;

        int target=total/2;
        vector<int> dp(target+1, false);
        dp[0]=true;

        for(int s : stones){
            for(int j=target;j>=s;j--){
                dp[j] = dp[j] || dp[j-s];
            }
        }

        for(int i=target;i>=0;i--){
            if(dp[i]){
                return total-2*i;
            }
        }

        return 0;
    }
};