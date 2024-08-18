class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }

        int temp = x;
        int rev = 0;
        while(temp>0){
            int lastDigit=temp%10;
            temp/=10;
            rev = rev*10 + lastDigit;
        }

        return x==rev ? true : false;
    }
};