class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int l=0,r=0;
        int maxf=0;
        int res=0;
        
        while(r<s.length()){
            count[s[r]-'A']++;
            maxf = max(maxf, count[s[r]-'A']);
            if(r-l+1-maxf>k){
                count[s[l]-'A']--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};