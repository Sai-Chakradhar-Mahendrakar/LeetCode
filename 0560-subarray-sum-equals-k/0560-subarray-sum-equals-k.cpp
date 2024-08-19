class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> mp;

        int sum = 0;
        int cnt = 0;
        mp[sum] = 1;

        for (auto x : nums) {
            sum += x;
            cnt += mp[sum - k];
            mp[sum]++;
        }

        return cnt;
    }
};