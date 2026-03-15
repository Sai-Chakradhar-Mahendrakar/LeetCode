class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<long long> dp(n+1, 0);

        dp[0]=startFuel;

        for(int i=0;i<n;i++){
            int pos=stations[i][0];
            int fuel=stations[i][1];
            for(int j=i;j>=0;j--){
                if(dp[j]>=pos){
                    dp[j+1] = max(dp[j+1], dp[j]+fuel);
                }
            }
        }

        for(int i=0;i<=n;i++){
            if(dp[i]>=target){
                return i;
            }
        }

        return -1;
    }
};