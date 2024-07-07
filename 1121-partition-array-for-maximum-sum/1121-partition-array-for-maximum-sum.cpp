class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& arr, int i, int k){
        if(i==arr.size()){
            return 0;
        }

        int &ans = memo[i];
        if(ans!=-1){
            return ans;
        }

        int mx=INT_MIN;
        for(int j=i;j<min((int)arr.size(),i+k);j++){
            mx = max(mx, arr[j]);
            // Add to Total Sum [15 2 3] -> [15 15 15] return 15*3
            ans = max(ans,mx*(j-i+1)+dp(arr, j+1, k));
        }
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo.resize(arr.size(),-1);
        return dp(arr, 0, k);
    }
};