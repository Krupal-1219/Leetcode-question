class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[idx][buy]
        vector <vector <int>> dp(n+2,vector <int> (2,0));
        for(int i = n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                if(buy){
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } 
                else{
                    // if we will sell than we can move to idx by 2 number as a cooldown
                    dp[i][buy] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
                }
            }
        } 
       return dp[0][1];       
    }
};