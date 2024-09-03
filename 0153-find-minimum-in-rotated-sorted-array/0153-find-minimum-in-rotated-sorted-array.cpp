class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans = nums[0];
        while(s<=e){
            // Already Sorted
            if(nums[s]<=nums[e]){
                ans = min(ans, nums[s]);
                break;
            }

            // Process
            int mid=(s+e)/2;
            if(nums[s]<=nums[mid]){
                ans = min(ans, nums[s]); 
                s=mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};