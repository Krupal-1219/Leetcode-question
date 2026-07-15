
class Solution {
public:
    int solve(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == nums.size()) return 0;

        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];

        // BUG FIX: Pass 'prev_idx' as is, do not add 1 to it!
        int nottake = solve(idx + 1, prev_idx, nums, dp); 
        
        int take = 0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            take = 1 + solve(idx + 1, idx, nums, dp);
        }
        
        return dp[idx][prev_idx + 1] = max(take, nottake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp array of size [n][n+1] to handle prev_idx from -1 to n-1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};