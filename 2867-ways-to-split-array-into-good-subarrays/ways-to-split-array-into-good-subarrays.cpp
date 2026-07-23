class Solution {
public:
    int mod = 1e9 + 7;

    // dp array stores the state for [idx][cnt]
    int solve(int idx, vector<int>& nums, int cnt, vector<vector<int>>& dp) {
        // Base case: If we finish the array, the current subarray MUST have a '1' to be valid
        if (idx < 0) return cnt == 1 ? 1 : 0;
        
        // Return memoized result
        if (dp[idx][cnt] != -1) return dp[idx][cnt];
        
        long long ans = 0;
        
        if (nums[idx] == 1) {
            if (cnt == 0) {
                // Prepend to current subarray, it now has one '1'
                ans = solve(idx - 1, nums, 1, dp);
            } else { 
                // cnt == 1: We already have a '1'. We are FORCED to put a split here.
                // The new subarray starts with this '1', so cnt remains 1.
                ans = solve(idx - 1, nums, 1, dp);
            }
        } else { // nums[idx] == 0
            if (cnt == 0) {
                // Prepend to current subarray, it still has zero '1's
                ans = solve(idx - 1, nums, 0, dp);
            } else { 
                // cnt == 1: We have a '1'. We can choose to split or not split!
                
                // Option 1: Don't split (keep '0' in the current subarray)
                long long dont_split = solve(idx - 1, nums, 1, dp);
                
                // Option 2: Split (start a new subarray with this '0', so cnt becomes 0)
                long long split = solve(idx - 1, nums, 0, dp);
                
                ans = (dont_split + split) % mod;
            }
        }
        
        return dp[idx][cnt] = ans % mod;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector <vector <int>> dp(nums.size(), vector <int> (2,-1));
        return solve(nums.size()-1, nums ,0,dp);
    }
};