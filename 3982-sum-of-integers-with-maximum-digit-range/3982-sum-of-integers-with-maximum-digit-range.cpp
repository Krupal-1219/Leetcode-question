class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        unordered_map <int,int> mpp;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int num_max = INT_MIN;
            int num_mini = INT_MAX;
            
            // FIX 1: Changed 'while' to 'do-while' so single-digit numbers like 0 are handled correctly
            do {
                num_max = max(num_max, num % 10);
                num_mini = min(num_mini, num % 10);
                num = num / 10;
            } while(num > 0);
            
            // FIX 2: Used 'nums[i]' instead of 'num' as the map key, because 'num' is now 0 after the loop
            mpp[nums[i]] = num_max - num_mini;
            maxi = max(maxi, mpp[nums[i]]);
        }
        for(int i = 0; i < n; i++){
            if(mpp[nums[i]] == maxi){
                sum += nums[i];
            }
        }
        return sum;
    }
};