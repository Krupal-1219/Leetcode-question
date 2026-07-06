class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end(),0);
        if(abs(target)> totalsum || (target+ totalsum)%2 != 0)return 0;

        int s1 = (target + totalsum)/2;
        int n = nums.size();

        vector <vector<int>> dp(n,vector <int> (s1+1,0));
        // base case 1 when s1 = 0
        for(int i =0;i<n;i++)dp[i][0] = 1;
        //base case idx = 0
        if (nums[0] == 0) {
            dp[0][0] = 2; // Two ways: pick 0 or do not pick 0
        } else {
            dp[0][0] = 1; // One way: do not pick
            if (nums[0] <= s1) {
                dp[0][nums[0]] = 1; // One way: pick nums[0]
            }
        }

        for(int i = 1;i<n;i++){
            for(int tar = 0;tar<=s1;tar++){
                int notpick = 0+ dp[i-1][tar];
                int pick = 0;
                if(nums[i] <= tar)pick = dp[i-1][tar-nums[i]];
                dp[i][tar] = pick + notpick;
            }
        }
        return dp[n-1][s1];
    }
};