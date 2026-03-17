class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(auto s: strs){
            int z=0, o=0;
            for(char c: s){
                if(c=='0'){
                    z++;
                }else{
                    o++;
                }
            }

            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--){
                    dp[i][j]=max(dp[i][j], 1+dp[i-z][j-o]);
                }
            }
        }

        return dp[m][n];
    }
};