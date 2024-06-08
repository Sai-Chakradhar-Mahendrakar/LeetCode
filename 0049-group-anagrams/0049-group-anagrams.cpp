class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(auto str:strs){
            auto key = str;
            sort(key.begin(),key.end());
            m[key].emplace_back(str);
        }
        
        for(auto pair:m){
            res.emplace_back(pair.second);
        }
        
        return res;
    }
};