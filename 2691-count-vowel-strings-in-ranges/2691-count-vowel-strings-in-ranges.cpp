class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n+1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i=0;i<n;i++){
            if(vowels.count(words[i][0]) && vowels.count(words[i].back())){
                prefixSum[i+1] = prefixSum[i]+1;
            }
            else{
                prefixSum[i+1]=prefixSum[i];
            }
        }
        vector<int> res;
        for(auto q:queries){
            res.push_back(prefixSum[q[1]+1] - prefixSum[q[0]]);
        }

        return res;
    }
};