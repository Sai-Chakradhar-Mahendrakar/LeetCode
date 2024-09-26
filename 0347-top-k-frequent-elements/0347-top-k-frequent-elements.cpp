class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // T:O(n) S:(n)
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto x:mp){
            freq[x.second].push_back(x.first);
        }

        vector<int> res;
        for(int i=freq.size()-1;i>=0;i--){
            for(int num:freq[i]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }

        return {};
    }
};