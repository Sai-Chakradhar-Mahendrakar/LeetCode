class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum=0;
        int cnt=0;
        mp[sum]=1;

        for(int x: nums){
            sum+=x;
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};