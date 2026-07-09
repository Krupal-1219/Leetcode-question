class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // value , idx
        unordered_map <int,int> mpp;
        int n = nums.size();
        for(int i= 0;i<n;i++){
            if(mpp.find(nums[i]) != mpp.end()){
                if(abs(mpp[nums[i]] - i) <= k)return true;
                else mpp[nums[i]] = i;
            }
            else mpp[nums[i]] = i;
        }
        return false;
    }
};