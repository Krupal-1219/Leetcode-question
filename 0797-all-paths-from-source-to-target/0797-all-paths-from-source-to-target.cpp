class Solution {
    private:
    void dfs(int node, vector <vector<int>>&graph,vector <int> & path,vector <vector <int>>&ans,int n){
        if(n-1 == node){
            ans.push_back(path);
            return;
        }
        for(auto it :graph[node]){
            path.push_back(it);
            dfs(it,graph,path,ans,n);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector <vector <int>> ans;
        vector <int> path;
        path.push_back(0);
        dfs(0,graph,path,ans,n);
        return ans;

    }
};