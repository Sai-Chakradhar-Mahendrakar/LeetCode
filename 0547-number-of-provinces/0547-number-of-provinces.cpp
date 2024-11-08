class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, 0);

        int conComp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected, vis, i, n);
                conComp++;
            }
        }
        
        return conComp;
    }
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i, int n){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(isConnected, vis, j, n);
            }
        }
    }
};