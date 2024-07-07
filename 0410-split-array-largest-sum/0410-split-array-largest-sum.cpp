class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& nums, int k, int idx){
        if(idx==nums.size()){
            if(k==0){
                return 0;
            }
            return 1e9;
        }

        if(k<=0){
            return 1e9;
        }

        int &ans = memo[idx][k];
        if(ans!=-1){
            return ans;
        }

        ans=1e9;

        int sum=0;
        for(int j=idx;j<nums.size();j++){
            sum+=nums[j];
            ans = min(ans, max(sum,dp(nums, k-1, j+1)));
        }

        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        memo.resize(nums.size(), vector<int>(k+1,-1));
        return dp(nums, k, 0);
    }
};