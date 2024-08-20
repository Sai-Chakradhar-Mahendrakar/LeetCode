class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> res;
        int n = intervals.size();
        // intervals.push_back(newInterval);

        // sort(intervals.begin(), intervals.end());
        // res.push_back(intervals[0]);
        // for(int i=1;i<intervals.size();i++){
        //     auto& lastElement = res.back();

        //     if(lastElement[1]>=intervals[i][0]){
        //         lastElement[1]=max(lastElement[1], intervals[i][1]);
        //     }
        //     else{
        //         res.push_back(intervals[i]);
        //     }
        // }
        

        // Efficient Method
        int i=0;
        while(i<n and intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i++]);
        }

        while(i<n and intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        res.push_back(newInterval);

        while(i<n){
            res.push_back(intervals[i++]);
        }
        

        return res;
    }
};