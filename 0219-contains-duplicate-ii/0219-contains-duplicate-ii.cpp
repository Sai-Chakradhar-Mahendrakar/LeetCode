class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                if(abs(i-mp[nums[i]])<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};