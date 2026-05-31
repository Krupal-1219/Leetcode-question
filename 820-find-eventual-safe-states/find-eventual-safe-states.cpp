class Solution {
    private: 
    bool dfs(int node, vector<int>& check, vector<int> &vis, vector <int>& pathvis, vector <vector <int>>& adj){
        vis[node] =1;
        pathvis[node] = 1;
        for (auto it : adj[node]){
            if(!vis[it]){
            if(dfs(it, check,vis, pathvis, adj) == true){
                check[it] = 0;
                return true; 
                }
            }
            else if(pathvis[it])return true;
        }
        check[node] =1;
        pathvis[node] =0 ;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);

        vector<int> safenodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,check,vis,pathvis,graph);
            }
        }
        for(int i =0; i<n;i++){
            if(check[i] == 1)safenodes.push_back(i);
        }
        return safenodes;
    }
};