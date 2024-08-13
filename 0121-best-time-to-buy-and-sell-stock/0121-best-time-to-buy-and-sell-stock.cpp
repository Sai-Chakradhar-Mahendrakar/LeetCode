class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,l=0,r=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                maxProfit = max(maxProfit, prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxProfit;
    }
};