class Solution {
public:
    string minWindow(string s, string t) {
        int fp[256] = {0};
        int fs[256] = {0};
        
        for(int i=0;i<t.size();i++){
            fp[t[i]]++;
        }

        int cnt = 0;
        int start = 0;
        int startWin = -1;
        int win = 0;
        int minWin = INT_MAX;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            fs[ch]++;

            if(fp[ch]!=0 and fs[ch]<=fp[ch]){
                cnt++;
            }

            // Overfitting
            if(cnt==t.size()){
                while(fs[s[start]]>fp[s[start]]){
                    fs[s[start]]--;
                    start++;
                }

                win = i-start+1;
                if(win<minWin){
                    minWin = win;
                    startWin = start;
                }
            }
        }
        return startWin==-1? "": s.substr(startWin, minWin);
    }
};