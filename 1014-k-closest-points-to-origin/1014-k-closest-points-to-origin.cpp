class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> tri;
        for(auto p:points){
            tri.push_back({p[0]*p[0]+p[1]*p[1],p[0],p[1]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mH(tri.begin(), tri.end());
        vector<vector<int>> res;
        while(k--){
            auto ele = mH.top();
            mH.pop();
            res.push_back({ele[1], ele[2]});
        }

        return res;
    }
};