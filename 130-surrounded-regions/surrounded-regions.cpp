class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat, int drow[], int dcol[]) {

        vis[row][col] = 1;

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                mat[nrow][ncol] == 'O') {

                dfs(nrow, ncol, vis, mat, drow, dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Traverse first and last row
        for (int j = 0; j < m; j++) {

            // top row
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, drow, dcol);
            }

            // bottom row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, drow, dcol);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {

            // left column
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, drow, dcol);
            }

            // right column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, drow, dcol);
            }
        }

        // Convert surrounded O -> X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};