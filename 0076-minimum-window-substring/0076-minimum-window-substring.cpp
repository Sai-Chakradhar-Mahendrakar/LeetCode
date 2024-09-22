class Solution {
public:
    string minWindow(string s, string t) {
        int fp[256] = {0};
        int fs[256] = {0};
        
        for(int i=0;i<t.size();i++){
            fp[t[i]]++;
        }

        int cnt=0;
        int l=0;
        int r=0;
        int startWin=-1;
        int minWin=INT_MAX;

        while(r<s.size()){
            char ch=s[r];
            fs[ch]++;

            if(fp[ch]!=0 && fs[ch]<=fp[ch]){
                cnt++;
            }

            if(cnt==t.size()){
                while(fs[s[l]]>fp[s[l]]){
                    fs[s[l]]--;
                    l++;
                }

                if(r-l+1<minWin){
                    minWin=r-l+1;
                    startWin=l;
                }
            }
            r++;
        }
        return startWin==-1?"":s.substr(startWin, minWin);
    }
};