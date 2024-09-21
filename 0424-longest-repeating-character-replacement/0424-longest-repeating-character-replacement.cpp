class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int n=s.size();
        int maxSize=0;
        int res=0;
        unordered_map<char, int> mp;
        while(r<n){
            mp[s[r]]++;
            maxSize=max(maxSize, mp[s[r]]);

            if(r-l+1-maxSize>k){
                mp[s[l]]--;
                l++;
            }

            res=max(res, r-l+1);
            r++;
        }
        return res;
    }
};