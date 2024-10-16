class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long mod=1e9+7, total=0, res=1;
	    vector<int> dp(k);
	    dp[0]=1;
	    for(auto x:nums){
	    	for(int i=k-1-x;i>=0;i--){
	    		dp[i+x] = (dp[i]+dp[i+x])%mod;
	    	}
	    	res=res*2%mod;
	    	total+=x;
	    }
    
	    for(int i=0;i<k;i++){
	    	res-=(total-i<k) ? dp[i] : dp[i]*2;
	    }
    
	    return (res%mod+mod)%mod;
    }
};