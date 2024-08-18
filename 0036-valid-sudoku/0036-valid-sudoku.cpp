class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};
        
        for(int r = 0; r < cnt; ++r){
            for(int c = 0; c < cnt; ++c){
                if(board[r][c] == '.')
                    continue;
                
                int idx = board[r][c] - '0' - 1;
                int area = (r/3)*3 + (c/3);
            
                if(row[r][idx] || col[c][idx] || sub[area][idx]){
                    return false;
                }
                
                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};