class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n =prices.size();
    vector <vector <int>> dp(n+1,vector <int>(2,0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            long long profit =0;
            if(buy){
                long long buyele = -prices[i] + dp[i+1][0];
                long long notbuy = 0 + dp[i+1][1];
                profit = max(buyele,notbuy);
            }
            else {
                long long sellele = prices[i] + dp[i+1][1];
                long long notsell = 0 + dp[i+1][0];
                profit = max(sellele, notsell);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
    }
};