class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector <pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector <int> dist(n+1,INT_MAX);
        // dist,node in priority queue
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            if(dist[node] != INT_MAX){
                for(auto iter : adj[node]){
                    int adjnode = iter.first;
                    int edgwt = iter.second;
                    if(dis + edgwt < dist[adjnode]){
                        dist[adjnode] = dis + edgwt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<= n;i++){
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};