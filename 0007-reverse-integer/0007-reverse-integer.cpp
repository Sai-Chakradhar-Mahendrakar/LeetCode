class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0){
            int temp = x%10;
            x /= 10;
            if(rev > INT_MAX/10 or (rev ==INT_MAX/10 and temp>7)){
                return 0;
            }
            if(rev < INT_MIN / 10 or (rev == INT_MIN / 10 and temp < -8)){
                return 0;
            }
            rev = rev*10 + temp;
        }
        return rev;
    }
};