class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int size = dfs(grid, r, c, i, j);
                    ans = max(ans, size);
                }
            }
        }

        return ans;
    }

    private:
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int dfs(vector<vector<int>>& grid, int r, int c, int i, int j){
            if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==0){
                return 0;
            }
            
            grid[i][j]=0;
            int cnt=1;

            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];

                cnt += dfs(grid, r, c, nx, ny);
            }

            return cnt;
        }
};