class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};