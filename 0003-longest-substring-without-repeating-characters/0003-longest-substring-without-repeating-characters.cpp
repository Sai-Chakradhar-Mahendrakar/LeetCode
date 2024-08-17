class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int win=0;
        int maxWin=INT_MIN;
        unordered_map<char, int> mp;

        while(r<s.size()){
            char ch = s[r];

            if(mp.count(ch) and mp[ch]>=l){
                l = mp[ch]+1;
                win = r-l;
            }

            mp[ch]=r;
            win = r-l+1;
            r++;

            if(win>maxWin){
                maxWin = win;
            }
        }
        return maxWin;

    }
};