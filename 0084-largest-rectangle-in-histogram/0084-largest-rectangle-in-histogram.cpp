class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        
        stack<pair<int,int>> s;
        int res = 0;
        
        for(int i=0;i<n;i++){
            int start = i;
            
            while(!s.empty() and s.top().second>heights[i]){
                int index = s.top().first;
                int width = i-index;
                int height = s.top().second;
                
                s.pop();
                res = max(res, height*width);
                
                start = index;
            }
            s.push({start, heights[i]});
        }
        
        while(!s.empty()){
            int width = heights.size() - s.top().first;
            int height = s.top().second;
            s.pop();
            
            res = max(res, height * width);
        }
        
        return res;
    }
};