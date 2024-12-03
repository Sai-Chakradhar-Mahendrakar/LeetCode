class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();

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
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};