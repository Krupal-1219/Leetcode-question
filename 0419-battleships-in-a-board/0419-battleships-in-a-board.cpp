class Solution {
public:
    void dfs(int row, int col, vector <vector <char>>& board, vector <vector<int>>& vis,int n,int m){
        if(vis[row][col] == 1)return;
        vis[row][col] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>= 0&&nrow<m && ncol>= 0&& ncol<n && board[nrow][ncol] == 'X' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis,n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector <vector<int>> vis(m,vector <int>(n,0));

        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,board,vis,n,m);
                }
            }
        }
        return cnt;
    }
};