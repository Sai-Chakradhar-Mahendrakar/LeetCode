class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int prevIdx=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prevIdx!=-1 && i-prevIdx-1<k){
                    return false;
                }
                prevIdx=i;
            }
        }
        return true;
    }
};