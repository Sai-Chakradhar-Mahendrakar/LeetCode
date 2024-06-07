class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        int h[26]={0};
        for(auto i:s){
            h[i-'a']++;
        }
        for(auto i:t){
            int x = --h[i-'a'];
            if(x<0){
                return false;
            }
        }
        return true;
    }
};