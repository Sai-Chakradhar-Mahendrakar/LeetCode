class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
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