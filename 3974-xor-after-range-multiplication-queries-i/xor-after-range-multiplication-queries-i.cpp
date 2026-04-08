class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int MOD = 1000000007;
        for(int i = 0 ;i <n; i++){
            for( int idx = queries[i][0]; idx <= queries[i][1] ; idx = idx + queries[i][2]){
                nums[idx] = (1LL * nums[idx] * queries[i][3]) %MOD;
            }
        }
        int xor_sum = 0;
        for (int i = 0; i< nums.size(); i++){
            xor_sum = xor_sum^nums[i];
        }
        return xor_sum;
    }
};