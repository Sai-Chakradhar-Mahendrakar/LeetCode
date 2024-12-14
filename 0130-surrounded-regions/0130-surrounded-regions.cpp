class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r==0){
            return;
        }
        int c=board[0].size();

        queue<pair<int, int>> q;
        for(int i=0;i<r;i++){
            for(int j:{0, c-1}){
                if(board[i][j]=='O'){
                    q.push({i, j});
                    board[i][j]='S';
                }
            }
        }

        for(int j=0;j<c;j++){
            for(int i:{0, r-1}){
                if(board[i][j]=='O'){
                    q.push({i, j});
                    board[i][j]='S';
                }
            }
        }


        int d[] = {0, 1, 0, -1, 0};

        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=i+d[k];
                int ny=j+d[k+1];
                if(nx>=0 && nx<r && ny>=0 && ny<c && board[nx][ny]=='O'){
                    board[nx][ny]='S';
                    q.push({nx, ny});
                }

            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='S'){
                    board[i][j]='O';
                }
            }
        }
    }
};