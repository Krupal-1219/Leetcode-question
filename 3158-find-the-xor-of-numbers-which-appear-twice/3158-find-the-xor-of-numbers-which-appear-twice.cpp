class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        // nums[i], cnt;
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        for(int i =0 ;i<n;i++){
            if(mpp[nums[i]] == 1)ans = ans^nums[i];
            mpp[nums[i]]++;
        }
        return ans;

    }
};