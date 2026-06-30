class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector <vector <int>> dp(n,vector<int>(m,-1));

        for(int i = 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(i == 0 && j == 0)dp[i][j] = arr[i][j];
                else{
                    int up = arr[i][j] , left = arr[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up = INT_MAX;
                    if(j>0) left += dp[i][j-1];
                    else left = INT_MAX;
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};