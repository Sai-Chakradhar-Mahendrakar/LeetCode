class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto num:nums){
            m[num]++;
        }
        
        int n = nums.size();
        vector<vector<int>> buc(n+1);
        for(auto it:m){
            buc[it.second].emplace_back(it.first);
        }
        
        vector<int> res;
        for(int i = n; i >= 0 && res.size() < k; --i) {
            if(!buc[i].empty()) {
                res.insert(res.end(), buc[i].begin(), buc[i].end());
            }
        }
        res.resize(k); 
        return res;
    }
};