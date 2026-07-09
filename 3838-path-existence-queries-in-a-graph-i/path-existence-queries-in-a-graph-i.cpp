class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        // Path compression
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        // Step 1: Pair values with their original indices and sort by value
        vector<pair<int, int>> sortedNodes(n);
        for (int i = 0; i < n; i++) {
            sortedNodes[i] = {nums[i], i};
        }
        sort(sortedNodes.begin(), sortedNodes.end());

        // Step 2: Only compare adjacent elements in sorted order O(N log N)
        for (int i = 0; i < n - 1; i++) {
            if (sortedNodes[i + 1].first - sortedNodes[i].first <= maxDiff) {
                dsu.unionBySize(sortedNodes[i].second, sortedNodes[i + 1].second);
            }
        }

        // Step 3: Answer queries in O(1) amortized time per query
        vector<bool> ans;
        ans.reserve(queries.size());
        for (int i = 0; i < queries.size(); i++) { // Fixed: iterate up to queries.size()
            int u = queries[i][0];
            int v = queries[i][1];
            // Fixed: use parentheses () instead of [] for method calls
            if (dsu.findParent(u) == dsu.findParent(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};