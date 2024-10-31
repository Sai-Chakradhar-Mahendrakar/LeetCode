class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(backtrack(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(int i, int j, int k, vector<vector<char>>& board, string word){
        if(k==word.size()){
            return true;
        }
        
        int n=board.size();
        int m=board[0].size();

        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[k]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        if(backtrack(i+1, j, k+1, board, word) || 
        backtrack(i-1, j, k+1, board, word) ||
        backtrack(i, j+1, k+1, board, word) || 
        backtrack(i, j-1, k+1, board, word))
        {
            return true;
        }

        board[i][j] = temp;
        return false;
    }
};