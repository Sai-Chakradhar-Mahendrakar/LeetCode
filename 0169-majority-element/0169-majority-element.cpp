class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        int maxCnt=INT_MIN;
        int maxInd;
        for(auto x:mp){
            auto freq = x.second;
            auto num = x.first;
            if(maxCnt<freq){
                maxCnt = freq;
                maxInd = num;
            }
        }
        return maxInd;
    }
};