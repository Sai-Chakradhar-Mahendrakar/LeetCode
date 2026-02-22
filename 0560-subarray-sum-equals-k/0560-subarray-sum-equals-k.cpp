class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0]=1;
        int sum=0, cnt=0;
        for(int num: nums){
            sum+=num;
            cnt+=freq[sum-k];
            freq[sum]++;
        }
        return cnt;
    }
};