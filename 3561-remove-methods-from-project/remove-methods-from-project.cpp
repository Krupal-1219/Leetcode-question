class Solution {
public:
    void dfs(int node, vector <int>& vis, vector <vector <int>> & adj){
        vis[node] = 1;

        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode, vis,adj);
            }
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector <vector <int>> adj(n);
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector <int> vis(n,0);
        vis[k] =1;
        dfs(k,vis,adj);
        vector <int> ans;
        for(auto & it : invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                for(int i = 0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i =0;i<n;i++){
            if(!vis[i])ans.push_back(i);
        }
        return ans;
    }
};