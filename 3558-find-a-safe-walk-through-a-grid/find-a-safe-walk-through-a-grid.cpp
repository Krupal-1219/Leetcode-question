class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       int n = grid.size();
       int m = grid[0].size();
        // we create the healtharr with INT_MIN since here we have to subtract the health if there is 1 
       vector <vector <int>> harr(n,vector<int>(m,INT_MIN));
       harr[0][0] = grid[0][0];
       priority_queue<pair<int,pair<int,int>>> pq;
       pq.push({health - grid[0][0], {0,0}});
       vector <int> drow = {-1,0,1,0};
       vector <int> dcol = {0,-1,0,1};
       while(!pq.empty()){
        int h = pq.top().first, row = pq.top().second.first , col = pq.top().second.second;
        pq.pop();
        if(h<harr[row][col])continue;
            for(int i = 0; i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow< n && ncol>=0 && ncol<m){
                    int nh = h-grid[nrow][ncol];
                    if(nh > harr[nrow][ncol]){
                        harr[nrow][ncol] = nh;
                        pq.push({nh,{nrow,ncol}});
                    }
                }
            }
       }
       return harr[n-1][m-1] >= 1;
    }
};