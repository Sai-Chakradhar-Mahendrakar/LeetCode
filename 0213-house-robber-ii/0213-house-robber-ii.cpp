class Solution {
public:
    int dp(vector<int> &nums, int idx, int n){
        int prev1 = 0;
        int prev2 = 0;

        for(int i=idx;i<=n;i++){
            int cur = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int range1 = dp(nums,0,n-2);
        int range2 = dp(nums,1,n-1);

        return max(range1, range2);
    }
};