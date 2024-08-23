class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int sign=1;
        int i=0;

        while(s[i]==' '){
            i++;
        }

        if(s[i]=='-' or s[i]=='+'){
            sign = (s[i]=='-')? -1:1;
            i++;
        }

        while(i<s.size() and isdigit(s[i])){
            ans = ans*10 +(s[i]-'0');

            if(ans*sign <= INT_MIN){
                return INT_MIN;
            }

            if(ans*sign >= INT_MAX){
                return INT_MAX;
            }

            i++;
        }
        return ans*sign;
    }
};