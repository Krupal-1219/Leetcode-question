class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        // Changed to i <= n to ensure the nth element is also initialized
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findparent(int node) {
        if(node == parent[node]) return node;
        // FIX: Use parentheses () to call a function, not brackets []
        return parent[node] = findparent(parent[node]); 
    }

    void unionbysize(int u, int v) {
        // FIX: Use parentheses () for function calls
        int pu = findparent(u);
        int pv = findparent(v);
        
        if(pu == pv) return;
        
        // FIX: Compare and update the sizes and parents of the ULTIMATE parents (pu, pv), not the original nodes (u, v)
        if(size[pu] < size[pv]) {
            parent[pu] = pv;        // Assign to the parent array, not the function
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;        // Assign to the parent array, not the function
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for(auto it : edges) {
           ds.unionbysize(it[0], it[1]);
        }
        
        return ds.findparent(source) == ds.findparent(destination);
    }
};