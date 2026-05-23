class Solution {
public:

    void bfs(int row, int col,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        q.push({row, col});

        vis[row][col] = 1;

        // 4 directions
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int currow = q.front().first;
            int curcol = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = currow + delrow[i];
                int ncol = curcol + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == '1' &&
                   !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(!vis[row][col] &&
                   grid[row][col] == '1') {

                    bfs(row, col, grid, vis);

                    cnt++;
                }
            }
        }

        return cnt;
    }
};