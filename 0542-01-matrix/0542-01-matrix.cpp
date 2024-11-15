class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int, int >>q;
        int d[] = {0, 1, 0, -1, 0};

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=i+d[k];
                int ny=j+d[k+1];
                if(nx<0 || nx==r || ny<0 || ny==c || mat[nx][ny]!=-1){
                    continue;
                }
                mat[nx][ny]=mat[i][j]+1;
                q.push({nx, ny});
            }
        }

        return mat;
    }
};