class Solution {
public:
    // int dp(vector<int>& nums, int i){
    //     if(i==nums.size()){
    //         return 1;
    //     }
    //     int ans = dp(nums, i+1);
        
    //     return max(ans, nums[i]*dp(nums,i+1));
    // }
    int maxProduct(vector<int>& nums) {
    //    return dp(nums, 0); 
        int n=nums.size();
        double mp = INT_MIN;
        double pre = 1;
        double suff = 1;

        for(int i=0;i<n;i++){
            if(pre == 0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            mp = max(mp, max(pre, suff));
        }

        return mp;
    }
};