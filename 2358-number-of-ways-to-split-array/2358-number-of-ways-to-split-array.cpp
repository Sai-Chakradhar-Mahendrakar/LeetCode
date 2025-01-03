class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long l=0;
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        int cnt=0;
        for(int i=0;i<n-1;i++){
            l+=nums[i];
            long long r=sum-l;
            if(l>=r){
                cnt++;
            }
        }
        return cnt;
    }
};