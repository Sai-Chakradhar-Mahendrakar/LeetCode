class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int res=0;
        int oddCnt=0;
        vector<int> freq(n+1, 0);
        freq[0]=1;
        while(r<n){
            if(nums[r]%2){
                oddCnt++;
            }

            if(oddCnt>=k){
                res+=freq[oddCnt-k]; // valid Subarr present ending r
            }

            freq[oddCnt]++;
            r++;
        }
        return res;
    }
};