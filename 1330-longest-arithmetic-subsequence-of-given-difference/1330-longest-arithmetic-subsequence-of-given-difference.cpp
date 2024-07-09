class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> diffArr(40001);
        int ans=1;
        for(auto x: arr){
            diffArr[x+20000] = diffArr[x-difference+20000]+1;
            ans = max(ans, diffArr[x+20000]);
        }
        return ans;
    }
};