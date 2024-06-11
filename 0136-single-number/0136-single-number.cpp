class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniq=0;
        for(auto x:nums){
            uniq ^= x;
        }
        return uniq;
    }
};