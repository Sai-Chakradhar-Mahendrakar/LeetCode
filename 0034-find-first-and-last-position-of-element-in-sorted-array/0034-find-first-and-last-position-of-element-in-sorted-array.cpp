class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        int lb=lowerBound(nums, x);
        int ub=upperBound(nums, x);

        
        if (lb == nums.size() || nums[lb] != x) {
            return {-1, -1};
        }

        return {lb, ub-1};
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
    int upperBound(vector<int>& nums, int x){
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size();

        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]>x){
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