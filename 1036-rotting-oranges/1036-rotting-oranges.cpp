class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        return bfs(grid, r, c);
    }

private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        int ans = -1;
        int fresh = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<vector<int>> dist(r, vector<int>(c,0));
        if(fresh==0){
            return 0;
        }

        while(!q.empty()){
            pair<int, int> pr = q.front();
            int x = pr.first;
            int y = pr.second;

            q.pop();

            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];

                if(xx>=0 and xx<r and yy>=0 and yy<c and grid[xx][yy]==1){
                    q.push({xx, yy});
                    grid[xx][yy]=2;
                    dist[xx][yy]= dist[x][y]+1;
                }
            }
        }
        int maxi=-1;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
                maxi = max(maxi , dist[i][j]);
            }
            
        }
        return maxi;
    }
};