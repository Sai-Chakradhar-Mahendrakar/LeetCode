class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        bool frow=0;
        bool fcol=0;

        // Cols
        for (int i=0;i<rows;i++) {
            if (mat[i][0] ==0) {
                fcol=true;
                break;
            }
        }

        // Rows
        for(int i=0;i<cols;i++){
            if(mat[0][i]==0){
                frow = true;
                break;
            }
        }
        
        // Others
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(mat[i][j]==0){
                    mat[0][j]=mat[i][0]=0;
                }
            }
        }

        for(int i=1;i<rows;i++){
            if(mat[i][0]==0){
                for(int j=1;j<cols;j++){
                    mat[i][j]=0;
                }
            }
        }

        for(int j=1;j<cols;j++){
            if(mat[0][j]==0){
                for(int i=1;i<rows;i++){
                    mat[i][j]=0;
                }
            }
        }        

        if(fcol){
            for(int i=0;i<rows;i++){
                mat[i][0]=0;
            }
        }

        if(frow){
            for(int j=0;j<cols;j++){
                mat[0][j]=0;
            }
        }
    }
};