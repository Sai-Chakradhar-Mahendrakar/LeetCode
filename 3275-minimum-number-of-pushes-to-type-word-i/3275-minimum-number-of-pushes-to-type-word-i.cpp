class Solution {
public:
    int minimumPushes(string word) {
        int len = word.length();
        int rem = len%8;
        int div = len/8;

        int sum = (div*(div+1))/2;
        return rem*(div+1) + 8*(sum);
    }
};