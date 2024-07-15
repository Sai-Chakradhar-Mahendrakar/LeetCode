class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0); 
        
        for (int i = 0; i < V; ++i) {
            if (visited[i] == 0) { // If the node is not yet colored
                if (!dfs(graph, i, visited, 1)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool dfs(vector<vector<int>> &adj, int node, vector<int>& visited, int color) {
        visited[node] = color;
        
        for (auto nbr : adj[node]) {
            if (visited[nbr] == 0) {
                if (!dfs(adj, nbr, visited, 3 - color)) {
                    return false;
                }
            } else if (visited[nbr] == color) {
                return false;
            }
        }
        
        return true;
    }
};
