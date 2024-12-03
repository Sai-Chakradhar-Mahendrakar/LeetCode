class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        // n+m+2*n*m
        int r=mat.size();
        int c=mat[0].size();
        vector<bool> row(r, false);
        vector<bool> col(c, false);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row[i] || col[j]){
                    mat[i][j]=0;
                }
            }
        }
    }
};