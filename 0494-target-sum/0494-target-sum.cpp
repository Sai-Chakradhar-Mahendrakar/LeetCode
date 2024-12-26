class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, target, 0, 0);
    }
private:
    int backtrack(vector<int>& nums, int target, int idx, int sum){
        if(idx>=nums.size()){
            return sum==target ? 1 : 0;
        }

        int sub = backtrack(nums, target, idx+1, sum-nums[idx]);
        int add = backtrack(nums, target, idx+1, sum+nums[idx]);

        return sub+add;
    }
};