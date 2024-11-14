class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(), nums.end()); 

        int res=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            if(makeDivisor(nums, mid)<=threshold){
                res=min(res, mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
private:
    int makeDivisor(auto nums, auto mid){
        int sum=0;
        for(auto num:nums){
            sum+=ceil((double)num/mid);
        }
        return sum;
    }
};