class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        while(s<e){
            int mid=(s+e)/2;

            if(mid%2){
                mid--;
            } 

            if(nums[mid]==nums[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
        return nums[s];
    }
};