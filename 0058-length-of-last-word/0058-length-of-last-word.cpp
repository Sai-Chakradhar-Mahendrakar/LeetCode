class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int cur=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                cur++;
            }
            else{
                if(cur!=0){
                    res = cur;
                }
                cur=0;
            }
        }
        if(cur!=0){
            res = cur;
        }
        return res;
    }
};