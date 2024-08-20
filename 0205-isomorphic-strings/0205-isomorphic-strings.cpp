class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char, char> mpS;
        unordered_map<char, char> mpT;

        for(int i=0;i<s.size();i++){
            if(mpS.find(s[i])==mpS.end()){
                mpS[s[i]]=t[i];
            }
            else if(mpS[s[i]]!=t[i]){
                return false;
            }

            if(mpT.find(t[i])==mpT.end()){
                mpT[t[i]]=s[i];
            }
            else if(mpT[t[i]]!=s[i]){
                return false;
            }
            
        }

        return true;
    }
};