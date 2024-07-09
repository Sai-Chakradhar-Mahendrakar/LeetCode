class Solution {
public:
    vector<vector<int>> memo;

    int dp(int i, int sum, vector<int>& nums){
        if(sum==0) return 1;
        if(i==nums.size()) return 0;

        if(memo[i][sum]!=-1){
            return memo[i][sum];
        }

        int ans = 0;
        
        if(sum>=nums[i]){
            ans |= dp(i+1, sum-nums[i], nums);
        }
        ans |= dp(i+1, sum, nums);

        return memo[i][sum] = ans;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2){
            return 0;
        }
        memo.resize(n+1, vector<int>(sum,-1));
        return dp(0, sum/2, nums);
    }
};