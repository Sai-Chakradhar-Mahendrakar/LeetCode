class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());

        return gcd(maxNum, minNum);
    }

    int gcd(int num1, int num2){
        if(num2==0){
            return num1;
        }
        return gcd(num2, num1%num2);
    }
};