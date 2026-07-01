class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Base case: first row is just the matrix values
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the DP table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i-1][j];
                
                int ld = matrix[i][j];
                // Use dp table, not matrix, for the previous step
                if(j > 0) ld += dp[i-1][j-1];
                else ld = 1e9; // Safely acts as infinity
                
                int rd = matrix[i][j];
                // Use dp table, not matrix, for the previous step
                if(j < n-1) rd += dp[i-1][j+1];
                else rd = 1e9; // Safely acts as infinity
                
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        
        // Find the minimum value in the last row
        int minAns = 1e9;
        for(int j = 0; j < n; j++) {
            minAns = min(minAns, dp[n-1][j]);
        }
        
        return minAns;
    }
};