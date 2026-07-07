class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parentNode(n + 1, 0);
        vector<int> cand1, cand2;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (parentNode[v] == 0) {
                parentNode[v] = u;
            } else {
                cand1 = {parentNode[v], v}; // earlier edge
                cand2 = {u, v};             // later edge
                break;
            }
        }

        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) -> bool {
            int pa = find(a);
            int pb = find(b);

            if (pa == pb) return false;

            parent[pb] = pa;
            return true;
        };

        for (auto &e : edges) {
            if (!cand2.empty() && e == cand2) {
                continue;
            }

            int u = e[0];
            int v = e[1];

            if (!unite(u, v)) {
                if (cand1.empty()) {
                    return e;
                }

                return cand1;
            }
        }

        return cand2;
    }
};