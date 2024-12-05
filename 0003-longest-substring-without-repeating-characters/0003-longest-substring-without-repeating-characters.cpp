class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int win=0;
        int maxWin=0;
        unordered_map<char, int> mp;
        while(r<s.size()){
            char ch = s[r];
            if(mp.count(ch) and mp[ch]>=l){
                l = mp[ch]+1;
                win = r-l;
            }
            mp[ch]=r;
            win++;
            r++;
            maxWin=max(maxWin, win);
        }
        return maxWin;
    }
};