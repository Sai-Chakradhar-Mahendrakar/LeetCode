class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        vector<pair<char, int>> v(127);

        for(auto ch: s){
            int freq = v[ch].second;
            v[ch] = {ch, freq+1};
        }

        sort(v.begin(), v.end(), [&](const auto p1, const auto p2){
            return p1.second>p2.second;
        });

        for(auto p:v){
            int ch = p.first;
            int freq = p.second;
            string temp = string(freq, ch);
            ans+=temp;
        }

        return ans;
    }
};