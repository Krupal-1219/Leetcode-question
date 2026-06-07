class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <pair<int,int>> adj[n];

        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // stops,node,dist
        queue <pair <int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k)continue;
            
            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int egweight = iter.second;

                if(egweight + cost < dist[adjnode] && stops<=k){
                    dist[adjnode] = cost+ egweight;
                    q.push({stops+1,{adjnode, dist[adjnode]}});
                }

            }
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];
    }
};