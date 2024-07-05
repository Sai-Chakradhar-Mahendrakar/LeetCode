class Solution {
public:

    int countSubstrings(string s) {
        int cnt = 0;

        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));

        // One Digit
        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
            cnt++;
        }

        // Two Digits
        for(int i=0;i<s.length()-1;i++){
            dp[i][i+1]=(s[i]==s[i+1]);
            cnt += dp[i][i+1];
        }
        
        // Remaining
        for(int len=3;len<=s.length();len++){
            for(int i=0,j=len-1;j<s.length();i++,j++){
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                cnt += dp[i][j];
            }
        }

        return cnt;
    }
};