class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector <int> prefix_gcd;
        for(int i = 0;i<n;i++){
            maxi = max(maxi, nums[i]);
            prefix_gcd.push_back(gcd(maxi, nums[i]));
        }
        sort(prefix_gcd.begin(), prefix_gcd.end());
        long long ans = 0;
        int l = 0, r = n-1;
        while(l<r){
            ans +=gcd(prefix_gcd[l], prefix_gcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};