class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1){
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            auto& lastInterval = res.back();

            if(intervals[i][0]<=lastInterval[1]){
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};