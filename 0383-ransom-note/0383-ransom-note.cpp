class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int h[26]={0};

        for(auto ch:magazine){
            h[ch-'a']++;
        }

        for(auto ch: ransomNote){
            h[ch-'a']--;
            if(h[ch-'a']<0){
                return false;
            }
        }

        return true;
    }
};