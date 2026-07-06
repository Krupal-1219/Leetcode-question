class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // DP table using unsigned int to safely allow well-defined wrapping.
        // This avoids the Undefined Behavior (UB) crash of signed integer overflow.
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));
        
        // Base case: for the first coin (idx = 0)
        for(int tar = 0; tar <= amount; tar++) {
            dp[0][tar] = (tar % coins[0] == 0);
        }

        for(int i = 1; i < n; i++) {
            for(int tar = 0; tar <= amount; tar++) {
                
                unsigned int notpick = dp[i-1][tar]; 
                unsigned int pick = 0;
                
                if(coins[i] <= tar) {
                    pick = dp[i][tar - coins[i]];
                }
                
                dp[i][tar] = pick + notpick; 
            }
        }
        
        // Final answer safely converts back to int as per problem guarantees
        return dp[n-1][amount]; 
    }
};