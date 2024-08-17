class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int winSize = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum>=target){
                winSize = r-l+1;
                ans = min(ans, winSize);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};