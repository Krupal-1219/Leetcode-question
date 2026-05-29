class Solution {
private:
    bool dfs(int node,
             vector<int>& vis,
             vector<int>& pathvis,
             vector<vector<int>>& adj) {

        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {

                if(dfs(it, vis, pathvis, adj))
                    return true;
            }
            else if(pathvis[it]) {

                return true;
            }
        }

        pathvis[node] = 0;   // Backtrack

        return false;
}
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        for(int i = 0; i < V; i++) {

            if(!vis[i]) {

                if(dfs(i, vis, pathvis, adj))
                    return false;
            }
        }

        return true;
    }
};