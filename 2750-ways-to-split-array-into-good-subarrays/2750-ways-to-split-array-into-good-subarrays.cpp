class Solution {
public:
    int MOD=1000000000+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int ans=1;
        int prev=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(prev!=-1)
                {
                    ans=(1LL*ans*(i-prev))%MOD;
                }
                prev=i;
            }
        }
        return prev==-1?0:ans;
    }
};