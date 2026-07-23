class Solution {
public:
    // 1. Fixed typo (solve)
    // 2. Passed strings by reference (const string&)
    // 3. Passed the dp array by reference
    int solve(int i, int j, const string& s, const string& t, vector<vector<int>>& dp) {
        if (i < 0) return 1;
        if (j < 0) return 0; // if j < 0 and i >= 0

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = solve(i - 1, j - 1, s, t, dp);
        } else {
            dp[i][j] = solve(i, j - 1, s, t, dp);
        }
        
        return dp[i][j];
    }

    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // Edge cases
        if (n == 0) return true;
        if (n > m) return false;
        
        // 4. DP array passed to the helper function
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // 5. Fixed return syntax
        return solve(n - 1, m - 1, s, t, dp) == 1; 
    }
};