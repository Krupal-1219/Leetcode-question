class Solution {
public:
    int maxProduct(int n) {
        vector <int> nums;
        while(n!= 0){
            nums.push_back(n%10);
            n = n/10;
        }
        sort(nums.begin(), nums.end());
        return nums[nums.size()-1]*nums[nums.size()-2];
    }
};