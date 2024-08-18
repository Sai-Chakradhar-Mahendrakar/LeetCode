class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int r=matrix.size();
        int c=matrix.size();

        for(int i=0;i<r;i++){
            for(int j=0;j<i;j++){
                if(j==i){
                    continue;
                }
                else{
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<(c/2);j++){
                swap(matrix[i][j], matrix[i][c-j-1]);
            }
        }

    }
};