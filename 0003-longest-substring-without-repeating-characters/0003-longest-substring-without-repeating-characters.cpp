class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int start_win=-1;
        int win_size=0;
        int lar_win=0;

        unordered_map<char,int>m;
        while(j<s.length()){
            char ch = s[j];
            //present
            if(m.count(ch) and m[ch]>=i){
                i = m[ch]+1;
                win_size=j-i;
            }

            //not present
            m[ch]=j;
            win_size++;
            j++;

            if(win_size>lar_win){
                lar_win = win_size;
                start_win=i;
            }
        }
        return lar_win;
        // (s.substr(start_win,lar_win)).length();
    }
};