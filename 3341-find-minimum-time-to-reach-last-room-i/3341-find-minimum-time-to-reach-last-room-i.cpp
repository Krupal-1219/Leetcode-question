class Solution {
public:
    bool isinside(int i , int j , int n ,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector <vector<int>> time(n,vector <int>(m,INT_MAX));
        // {time,row,col} of pq
        time[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector <int> drow = {-1,0,1,0};
        vector <int> dcol = {0,-1,0,1};
        while(!pq.empty()){
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1)return t;
            for(int i = 0; i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isinside(nrow,ncol,n,m)== false)continue;
                int nextt = max(t,moveTime[nrow][ncol]) +1;
                if(nextt<time[nrow][ncol]){
                    time[nrow][ncol] = nextt;
                    pq.push({nextt,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};