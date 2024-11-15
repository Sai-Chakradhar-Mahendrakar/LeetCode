class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    dfs(grid, i, j, r, c, 2);
                }
            }
        }

        int ans=INT_MIN;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                ans=max(ans, grid[i][j]);
            }
        }
        return ans<=0? 0 : ans-2;
    }
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int min){
        if(i<0 || i==r || j<0 || j==c || grid[i][j]==0 || 
            (grid[i][j]<min && grid[i][j]>1)){
                return;
        }
        grid[i][j]=min;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(grid, nx, ny, r, c, min+1);
        }
    }
};