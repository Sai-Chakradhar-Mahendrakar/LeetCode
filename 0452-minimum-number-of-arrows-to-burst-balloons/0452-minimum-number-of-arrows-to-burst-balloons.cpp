class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res=points.size();
        int prevEnd = points[0][1];

        for(int i=1;i<points.size();i++){
            if(points[i][0]<=prevEnd){
                res--;
                prevEnd = min(prevEnd, points[i][1]);
            }
            else{
                prevEnd = points[i][1];
            }
        }

        return res;
    }
};