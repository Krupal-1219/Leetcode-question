class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      vector <vector <int>> dp(n,vector<int>(amount+1,0));

      for(int t =0 ;t<=amount;t++){
        if(t%coins[0] == 0)dp[0][t] = t/coins[0];
        else dp[0][t] = 1e9;
      }  
      for(int idx = 1; idx<n; idx++){
        for(int tar = 0;tar<= amount;tar++){
            int nottake = dp[idx-1][tar] + 0;
            int take = INT_MAX;
            if(coins[idx] <= tar) take = 1 + dp[idx][tar - coins[idx]]; // infinte coins case thus we stay at same idx so it will check the how many same coins will be selected
            dp[idx][tar] = min(take,nottake);
        }
      }
      int ans = dp[n-1][amount];
      if(ans>= 1e9)return -1;
      return ans;
    }
};