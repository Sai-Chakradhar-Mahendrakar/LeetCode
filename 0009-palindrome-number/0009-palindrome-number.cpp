class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        int temp = x;
        int rev = 0;
        while(temp>0){
            int lastDigit=temp%10;
            
            if (rev > (INT_MAX - lastDigit) / 10) {
                return false; // Overflow, so it can't be a palindrome
            }
            
            temp/=10;
            rev = rev*10 + lastDigit;
        }

        return x==rev;
    }
};