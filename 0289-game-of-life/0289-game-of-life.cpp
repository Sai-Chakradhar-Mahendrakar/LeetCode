class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> newBoard(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int cntOnes = cntNbrs(n, m, board, i, j);

                if(board[i][j]==0){
                    if(cntOnes==3){
                        newBoard[i][j]=1;
                    }
                }
                else{
                    if(cntOnes==2 or cntOnes==3){
                        newBoard[i][j]=1;
                    }
                }
            }
        }
        board = newBoard;
    }

private:
    int cntNbrs(int n, int m, vector<vector<int>> board, int i, int j){
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0 ,1};

        int cntOnes=0;

        for(int k=0;k<8;k++){
            int nbx = i+dx[k];
            int nby = j+dy[k];
            if(nbx>=0 and nbx<n and nby>=0 and nby<m){
                if(board[nbx][nby]==1 or board[nbx][nby]==2){
                    cntOnes++;
                }
            }
        }

        return cntOnes;
    }
};