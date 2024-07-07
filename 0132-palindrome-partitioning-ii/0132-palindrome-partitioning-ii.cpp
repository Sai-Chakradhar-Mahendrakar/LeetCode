class Solution {
public:
    vector<int> memo;
    vector<vector<int>> memo1;
    int isPalindrome(string& s, int i, int j){
        if(i==j) return true;
        if(i==j-1) return (s[i]==s[j]);
        if(memo1[i][j]!=-1) return memo1[i][j];
        return memo1[i][j]=isPalindrome(s,i+1,j-1) and (s[i]==s[j]);
    }

    int dp(string &s, int idx){
        if(idx==s.size()){
            return 0;
        }

        if(memo[idx]!=-1){
            return memo[idx];
        }

        int ans=INT_MAX;
        for(int j=idx;j<s.size();j++){
            if(isPalindrome(s, idx, j)){
                ans = min(ans, dp(s,j+1));
            }
        }

        ans+=1;
        return memo[idx]=ans;
    }

    int minCut(string s) {
        memo.resize(s.size(),-1);  
        memo1.resize(s.size(), vector<int>(s.size(),-1)); 
        return dp(s, 0)-1;
    }
};