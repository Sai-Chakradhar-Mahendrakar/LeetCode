class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> r(26, 0);
        for(auto ch: s){
            r[ch-'a']++;
        }
        vector<int> l(26, 0);
        unordered_set<int> S;
        for(int i=0;i<n;i++){
            int t = s[i]-'a';
            r[t]--;
            for(int j=0;j<26;j++){
                if(l[j]>0 && r[j]>0){
                    S.insert(26*t+j);
                }
            }
            l[t]++;
        }
        return S.size();
    }
};