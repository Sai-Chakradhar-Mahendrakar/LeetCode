class Solution {
public:
    bool isHappy(int n) {
        int slow = squareSum(n);
        int fast = squareSum(squareSum(n));

        while(slow!=fast and fast!=1){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return fast==1;
    }

private:
    int squareSum(int n){
        int curSum=0;
        while(n!=0){
            int rem = (n%10);
            curSum += rem*rem;
            n/=10;
        }
        return curSum;
    }
};