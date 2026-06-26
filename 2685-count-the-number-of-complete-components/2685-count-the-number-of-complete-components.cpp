class Solution {
public: 
    void bfs(int node, vector<int>& vis, vector <vector <int>>&adj, vector <int>&comp){
        queue<int> q;
        q.push(node);
        vis[node] =1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            comp.push_back(curr);
            for(auto it : adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] =1;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <vector<int>> adj(n);
        vector <int> vis(n,0);
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        for(int i = 0; i <n;i++){
            if(!vis[i]){
                vector<int> comp;
                bfs(i, vis,adj,comp);
                bool flag = true;
                for(auto it :comp){
                    if(adj[it].size() != comp.size()-1){
                        flag = false;
                        break;
                    }
                }
                if(flag)cnt++;
            }
        }
        return cnt;
    }
};