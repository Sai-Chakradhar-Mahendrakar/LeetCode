class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(), nums.end());
        int e=accumulate(nums.begin(), nums.end(), 0);
        int ans=0;

        while(s<=e){
            int mid=(s+e)/2;
            if(canSplit(nums, mid)>k){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
private:
    int canSplit(auto& nums, auto mid){
        int partition=1;
        int sum=0;
        for(auto x: nums){
            if(sum+x>mid){
                partition++;
                sum=0;
            }
            sum+=x;
        }
        return partition;
    }
};