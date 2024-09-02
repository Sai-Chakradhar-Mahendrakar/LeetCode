class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return lowerBound(nums, target);
    }
private:
    int lowerBound(vector<int>& nums, int x){
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size();

        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]>=x){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};