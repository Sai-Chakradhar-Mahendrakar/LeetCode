class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int r = matrix.size();
        if(r==0){
            return 0;
        }
        int c = matrix[0].size();

        vector<int>ps(c,0);
        int maxRecArea=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    ps[j]++;
                }
                else{
                    ps[j]=0;
                }
            }
            maxRecArea = max(maxRecArea, largestRectangle(ps));
        }

        return maxRecArea;
    }
private:
    int largestRectangle(vector<int>& arr){
        stack<pair<int, int>> st;
        int maxArea=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int start=i;
            while(!st.empty() && st.top().second>arr[i]){
                int idx = st.top().first;
                int w = i-idx;
                int h = st.top().second;

                st.pop();
                maxArea = max(maxArea, w*h);
                start = idx;
            }
            st.push({start, arr[i]});
        }

        while(!st.empty()){
            int w = n-st.top().first;
            int h = st.top().second;
            st.pop();
            maxArea = max(maxArea, w*h);
        }

        return maxArea;
    }
};