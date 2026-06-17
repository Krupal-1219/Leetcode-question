class Solution {
public:
    void dfs(vector <vector <int>>& stones, int node,vector <int> & vis){
        vis[node] =1;
        for(int j = 0; j<stones.size();j++){
            if((!vis[j]) && (stones[j][0] == stones[node][0]|| stones[j][1] == stones[node][1]))dfs(stones,j,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector <int> vis(n,0);
        int cnt = 0;
        for(int i = 0 ;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(stones,i,vis);
            }
        }
        return n-cnt;
    }
};