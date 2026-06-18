class Disjointset {
public:
    vector<int> parent, size;

    Disjointset(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findupar(parent[node]);
    }

    void unionbysize(int u, int v) {
        int pu = findupar(u);
        int pv = findupar(v);

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
private:
    bool isvalid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        Disjointset ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Connect all adjacent 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];

                    if (isvalid(newr, newc, n) &&
                        grid[newr][newc] == 1) {

                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;

                        ds.unionbysize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;

        // Step 2: Try converting each 0 into 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                set<int> components;

                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];

                    if (isvalid(newr, newc, n) &&
                        grid[newr][newc] == 1) {

                        components.insert(
                            ds.findupar(newr * n + newc)
                        );
                    }
                }

                int sizeTotal = 0;

                for (auto parent : components) {
                    sizeTotal += ds.size[parent];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: Handle case when grid is all 1's
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findupar(cellNo)]);
        }

        return mx;
    }
};