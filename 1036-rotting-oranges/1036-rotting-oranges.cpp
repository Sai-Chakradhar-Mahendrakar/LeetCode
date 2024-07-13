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

        q.push({-1, -1});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == -1) {
                ans++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    int nx = row + dx[i];
                    int ny = col + dy[i];

                    if (nx < 0 or nx >= r or ny < 0 or ny >= c) {
                        continue;
                    } else if (grid[nx][ny] == 1) {
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }

        if (fresh == 0) {
            return ans;
        }

        return -1;
    }
};