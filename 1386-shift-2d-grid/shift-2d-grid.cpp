class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int n = grid.size();
      int m = grid[0].size();
      vector <vector <int>> ans(n,vector <int> (m,0));
        int total = m*n;
        k = k%total;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int curridx = i*m + j;

                int newidx = (curridx + k)%total;
                int nrow = newidx/m;
                int ncol = newidx%m;
                ans[nrow][ncol] = grid[i][j];
            }
        }
        return ans;
    }
};