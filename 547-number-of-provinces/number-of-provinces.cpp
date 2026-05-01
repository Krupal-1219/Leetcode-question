class Solution {
public:
    void dfs(int node, vector<vector <int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n = isconnected.size();
        
        // FIX 1: Initialize adjacency list with 'n' empty rows
        vector<vector<int>> adj(n); 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isconnected[i][j] == 1 && i != j) {
                    // FIX 2: Only add the one direction. The loop will 
                    // catch the reverse direction on its own.
                    adj[i].push_back(j); 
                }
            }
        }
        
        vector<int> visited(n, 0);
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                cnt++;
                dfs(i, adj, visited);
            }
        }
        
        return cnt;
    }
};