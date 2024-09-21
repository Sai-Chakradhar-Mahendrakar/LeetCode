class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int start = 0;
        int ans=0;
        int i=0;

        while(i<n){
            while(i<n && k<1 && nums[i]==0){
                if(nums[start]==0){
                    k++;
                }

                ans = max(ans, i-start);
                start++;
            }

            if(i<n && k>0 && nums[i]==0){
                k--;
            }
            i++;
        }
        ans = max(ans, n-start);
        return ans;
    }
};