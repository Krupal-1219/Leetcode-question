class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int secmaxi = INT_MIN;
        for(int i =0;i<n;i++){
            if (nums[i] > maxi){
                secmaxi = maxi;
                maxi = nums[i];
            }
            else if (nums[i] > secmaxi){
                secmaxi = nums[i];
            }
        }
        return (maxi -1)*(secmaxi-1);
    }
};