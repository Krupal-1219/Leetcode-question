class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector <vector<int>> adj(V);
       for(auto & e: prerequisites){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
       }
       vector <int> indegree(V,0);
       for(int i =0 ;i<V;i++){
        for(auto it :adj[i]){
            indegree[it]++;
        }
       }
       queue <int>q;
       for(int i =0; i<V;i++){
        if(indegree[i] ==0){
            q.push(i);
        }
       }
       vector <int> ans;
       int visited =0;
       while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        visited++;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
       }
       reverse(ans.begin(), ans.end());
        if(visited == V)return ans;
        return{};
    }
};