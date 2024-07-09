class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int maxLength = 0;
        int currentEnd = INT_MIN;

        for(auto pair:pairs){
            if(pair[0]>currentEnd){
                currentEnd=pair[1];
                maxLength++;
            }
        }

        return maxLength;
    }
};