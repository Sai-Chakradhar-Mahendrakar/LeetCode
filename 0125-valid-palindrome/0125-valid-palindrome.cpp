class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            
            if(toupper(s[i])!=toupper(s[j])){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
};