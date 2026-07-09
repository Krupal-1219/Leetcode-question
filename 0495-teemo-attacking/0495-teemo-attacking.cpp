class Solution {
public:
    int findPoisonedDuration(vector<int>& nums, int duration) {
        int ans = 0;
        ans += duration;
        for(int i = nums.size()-2; i>=0;i--){
            if(nums[i] + duration < nums[i+1])ans+= duration;
            else ans += nums[i+1]-nums[i];
        }
        return ans;
    }
};