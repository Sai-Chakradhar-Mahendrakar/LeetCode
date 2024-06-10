class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxS=0, l=0, r=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                maxS = max(maxS, prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxS;
    }
};