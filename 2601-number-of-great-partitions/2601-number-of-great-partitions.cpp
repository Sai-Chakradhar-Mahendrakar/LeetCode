class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long mod = 1e9+7, total=0, res=1;
        vector<long> dp(k);
        dp[0]=1;
        for(auto a:nums){
            for(int i=k-1-a;i>=0;i--){
                dp[i+a] = (dp[i+a]+dp[i])%mod;
            }
            res = res*2%mod;
            total+=a;
        }
        for(int i=0;i<k;i++){
            res-=total-i<k?dp[i]:dp[i]*2;
        }
        return (res%mod+mod)%mod;
    }
};