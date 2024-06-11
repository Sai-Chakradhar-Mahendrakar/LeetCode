class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int cy = a&b;
            a ^= b;
            b = (unsigned)cy << 1;
        }
        return a;
    }
};