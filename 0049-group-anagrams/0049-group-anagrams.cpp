class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for(auto str: strs){
            auto org = str;
            sort(str.begin(), str.end());
            mp[str].push_back(org);
        }

        for(auto pair:mp){
            res.push_back(pair.second);
        }

        return res;
    }
};