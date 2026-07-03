class Solution {
public:
    bool subsetsumk(vector<int>& nums,int target){
        int n = nums.size();
        vector<vector<bool>> dp(n,vector <bool>(target+1, false));
        //base case for target
        for(int i = 0;i< n;i++)dp[i][0] = true;
        // base case for idx
        if(nums[0] <= target){
        dp[0][nums[0]] = true;
        }
        for(int i = 1; i< n;i++){
            for(int k = 1; k<= target;k++){
                bool nottake = dp[i-1][k];
                bool take = false;
                if(k>=nums[i]) take = dp[i-1][k-nums[i]];
                dp[i][k] = take || nottake;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if(totalsum %2 != 0)return false;
        int sum = totalsum/2;
        return subsetsumk(nums,sum);
    }
};