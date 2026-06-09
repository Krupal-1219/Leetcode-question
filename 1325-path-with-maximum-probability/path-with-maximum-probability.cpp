class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector <vector <pair<int,double>>> adj(n);
        for(int i = 0 ;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0.0);
        pq.push({1.0,start_node});
        dist[start_node] = 1.0;

        while(!pq.empty()){
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] != 0.0){            for(auto it : adj[node]){
                int adjnode = it.first;
                double prob = it.second;
                if(p*prob > dist[adjnode]){
                    dist[adjnode] = p*prob;
                    pq.push({dist[adjnode], adjnode});
                }
            }}
        }
        return dist[end_node];
    }
};