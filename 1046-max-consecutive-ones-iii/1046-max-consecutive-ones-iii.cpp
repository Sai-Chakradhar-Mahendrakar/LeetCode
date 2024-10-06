class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int n=nums.size();

        while(r<n){
            while(l<n && k==0 && nums[r]==0){
                if(nums[l]==0){
                    k++;
                }
                ans=max(ans, r-l);
                l++;
            }
            if(nums[r]==0 && k>0){
                k--;
            }
            r++;
        }
        ans=max(ans, n-l);
        return ans;
    }
};