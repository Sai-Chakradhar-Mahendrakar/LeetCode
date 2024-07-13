class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, r, c, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    private:
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        void dfs(vector<vector<char>>& grid, int r, int c, int i, int j){
            if(i<0 || i>=r || j<0 || j>=c || grid[i][j]=='0'){
                return;
            }
            
            grid[i][j]='0';

            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];

                dfs(grid, r, c, nx, ny);
            }
        }
};