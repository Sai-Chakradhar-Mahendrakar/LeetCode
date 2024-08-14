class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& prices, bool buy, int idx){
        if(idx==prices.size()){
            return 0;
        }

        int &ans = memo[idx][buy];
        if(ans!=-1){
            return ans;
        }

        // Exclude
        ans = dp(prices, buy, idx+1);

        // Include
        if(buy){
            // Buy
            ans = max(ans, -prices[idx]+dp(prices, false, idx+1));
        }else{
            // Sell
            ans = max(ans, prices[idx]+dp(prices, true, idx+1));
        }

        return ans;
    }
    int maxProfit(vector<int>& prices) {
        // memo.resize(prices.size(), vector<int>(2,-1));
        // return dp(prices, true, 0);
        int max=0;
        int start = prices[0];
        for(int i=1;i<prices.size();i++){
            if(start<prices[i]){
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
    }
};