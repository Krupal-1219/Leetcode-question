class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        for(int row =0 ;row<n;row++){
            for(int col = 0;col<m;col++){
                if(grid[row][col] == 1){
                    for(int k = 0;k <4;k++){
                        int nrow = drow[k] + row;
                        int ncol = dcol[k] + col;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol] == 0){
                            cnt++;
                        }
                        if(ncol == -1 && nrow<n && nrow >=0)cnt++;
                        if(ncol ==m && nrow<n && nrow >=0)cnt++;
                        if(nrow == n && ncol<m && ncol >=0 )cnt++;
                        if(nrow == -1 && ncol<m && ncol >=0)cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};