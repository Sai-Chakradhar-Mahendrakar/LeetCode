class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st; // index, height
        int maxArea=0;

        for(int i=0;i<n;i++){
            int start=i;
            while(!st.empty() && st.top().second>heights[i]){
                int idx = st.top().first;
                int width = i-idx;
                int height = st.top().second;

                st.pop();
                maxArea = max(maxArea, height*width);

                start=idx;
            }
            st.push({start, heights[i]});
        }

        // remaining
        while(!st.empty()){
            int width = heights.size() - st.top().first;
            int height = st.top().second;
            st.pop();

            maxArea = max(maxArea, height*width);
        }

        return maxArea;
    }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();