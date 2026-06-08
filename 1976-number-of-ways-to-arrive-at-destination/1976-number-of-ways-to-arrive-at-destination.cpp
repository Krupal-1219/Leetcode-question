class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        const int mod = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;

            if(dis > dist[node]) continue;

            for(auto &iter : adj[node]) {

                int adjnode = iter.first;
                int edw = iter.second;

                if(dis + edw < dist[adjnode]) {

                    dist[adjnode] = dis + edw;
                    ways[adjnode] = ways[node];

                    pq.push({dist[adjnode], adjnode});
                }
                else if(dis + edw == dist[adjnode]) {

                    ways[adjnode] =
                        (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};