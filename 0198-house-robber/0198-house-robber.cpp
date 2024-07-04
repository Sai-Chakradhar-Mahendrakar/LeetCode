class Solution {
public:
    // dp[i] = max(dp(i+1), dp(i+2)+nums[idx])
    // vector<int> memo;

    // int dp(vector<int> &nums, int idx, int n){
    //     if(idx>=n){
    //         return 0;
    //     }

    //     if(memo[idx]!=-1){
    //         return memo[idx];
    //     }

    //     int takeNextHouse = dp(nums,idx+1,n);
    //     int secondHouse = dp(nums,idx+2,n)+nums[idx];

    //     return max(takeNextHouse, secondHouse);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int takeNextHouse = 0;
        int secondHouse = 0;

        for(int i=0;i<n;i++){
            int current = max(takeNextHouse, secondHouse+nums[i]);
            secondHouse = takeNextHouse;
            takeNextHouse = current;
        }

        return takeNextHouse;  
    }
};