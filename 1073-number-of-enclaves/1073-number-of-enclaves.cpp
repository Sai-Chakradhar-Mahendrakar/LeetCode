class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || j==0 || i==r-1 || j==c-1) && grid[i][j]==1){
                    dfs(grid, i, j);
                }
            }
        }  
        return accumulate(grid.begin(), grid.end(), 0, [](int sum, auto row){
            return sum+accumulate(row.begin(), row.end(), 0);
        }); 
    }
private:
    int r;
    int c;
    int d[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int nx=i+d[k];
            int ny=j+d[k+1];
            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==1){
                dfs(grid, nx, ny);
            }
        }
    }
};