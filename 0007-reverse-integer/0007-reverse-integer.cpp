class Solution {
public:
    int reverse(int x) {
        int temp=x;
        int rev=0;

        bool neg=false;

        if(x<0){
            neg=true;
            temp*=-1;
        }

        while(temp>0){
            int lastDigit=temp%10;
            temp = temp/10;
            rev = rev*10 + lastDigit;
        }

        return neg ? rev*-1 : rev;
    }
};