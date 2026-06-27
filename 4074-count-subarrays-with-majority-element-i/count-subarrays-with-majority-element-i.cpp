class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int targetcnt = 0;
            for(int r = i; r<n;r++){
                if(nums[r]  == target){
                    targetcnt++;
                }
                int len = r-i+1;
                if(targetcnt>len/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};