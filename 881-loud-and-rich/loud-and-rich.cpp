class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        if(n == 1)return {0};
        vector <vector <int>> adj(n);
        vector <int> indegree(n, 0), ans(n);
        iota(ans.begin(), ans.end(), 0);
        if(richer.size() == 0)return ans;

        for(auto it : richer){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indegree[i] == 0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
                if(quiet[ans[node]] < quiet[ans[i]]){
                    ans[i] =ans[node];
                } 
                indegree[i]--;
                if(indegree[i] == 0)q.push(i);
            }
        }
        return ans;
    }
};