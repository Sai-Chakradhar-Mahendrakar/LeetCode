class Solution {
public:
    // dp(i) = dp(i+1)+dp(i+2)
    vector<int> memo;
    int dp(string& s, int idx, int n) {
        if (idx == n) {
            return 1;
        }

        if (s[idx] == '0') {
            return 0;
        }

        if(memo[idx] != -1){
            return memo[idx];
        }

        // Decode the current digit
        int ans = dp(s, idx + 1, n);

        // Decode the current and the next digit if it's valid
        if (idx + 1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            ans += dp(s, idx + 2, n);
        }

        return memo[idx] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        memo.resize(n, -1);
        return dp(s, 0, n);
    }
};