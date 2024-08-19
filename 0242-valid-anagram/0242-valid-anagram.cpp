class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        int h[26]={0};
        
        for(auto ch:s){
            h[ch-'a']++;
        }

        for(auto ch:t){
            int x = --h[ch-'a'];
            if(x<0){
                return false;
            }
        }

        return true;
    }
};