class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n, INF = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(N); // {weight, linear address}
        vector<int> di{1, -1, 0, 0};
        vector<int> dj{0, 0, 1, -1};

        auto lin_add = [&](int i_, int j_) -> int {
            return i_ * n + j_;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
                        adj[lin_add(i, j)].push_back({grid[ni][nj], lin_add(ni, nj)});
                    }
                }
            }
        }

        vector<int> dist(N, INF); dist[0] = grid[0][0]; // min time to wait to get to lin. add. i, j
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> q; 
        q.push({grid[0][0], 0});

        while (!q.empty()) {
            auto [wu, u] = q.top(); q.pop();

            for (auto [wv, v] : adj[u]) {
                int nd = max(wv, dist[u]);

                if (nd < dist[v]) {
                    dist[v] = nd;
                    q.push({nd, v});
                }
            }
        }

        return dist[N-1];
    }
};