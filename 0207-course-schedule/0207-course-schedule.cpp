class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> stack(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(graph, vis, stack, i)){
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& stack, int node){
        vis[node]=true;
        stack[node]=true;
        for(auto nbr: graph[node]){
            if(stack[nbr]==true){
                return true;
            }
            else if(!vis[nbr]){
                if(dfs(graph, vis, stack, nbr)){
                    return true;
                }
            }
        }
        stack[node]=false;
        return false;
    }
};