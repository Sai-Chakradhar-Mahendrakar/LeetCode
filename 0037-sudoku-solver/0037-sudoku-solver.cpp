class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>& board,int value){

        for(int k=0;k<9;k++){
        //row check
        if(board[i][k]==value) return false;
        //column check
        if(board[k][j]==value) return false;
        //3*3 box check
        if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==value) return false;
    }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //check for empty cells
                if(board[i][j]=='.'){
                    //insert
                    for(char value='1';value<='9';value++){
                        //checking for safety of row,col and 3*3 box
                        if(isSafe(i,j,board,value)){
                            board[i][j]=value;
                            //baaki recursion sambhaal leha
                            bool aageKaSolution=solve(board);
                            if(aageKaSolution==true) return true;
                            // else backtracking
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};