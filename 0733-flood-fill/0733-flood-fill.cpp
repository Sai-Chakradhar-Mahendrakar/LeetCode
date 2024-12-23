class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        int orgColor = image[sr][sc];

        if(orgColor==color){
            return image;
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int d[] = {0, -1, 0, 1, 0};
        while(!q.empty()){
            auto pixel = q.front();
            q.pop();
            image[pixel.first][pixel.second]=color;
            for(int i=0;i<4;i++){
                int nx=pixel.first+d[i];
                int ny=pixel.second+d[i+1];
                if(nx>=0 && nx<r && ny>=0 && ny<c && image[nx][ny]==orgColor){
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};