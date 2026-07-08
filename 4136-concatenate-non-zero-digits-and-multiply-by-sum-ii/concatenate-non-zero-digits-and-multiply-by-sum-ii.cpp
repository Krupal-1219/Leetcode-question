class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1e9 + 7;
        
        // 1. Precompute powers of 10 modulo 10^9 + 7
        vector<long long> power10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % mod;
        }
        
        // 2. Build Prefix Arrays in O(N) time
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            
            // Keep track of digit sums
            prefSum[i + 1] = prefSum[i] + digit;
            
            // Keep track of non-zero digit counts
            nonZeroCount[i + 1] = nonZeroCount[i] + (digit != 0 ? 1 : 0);
            
            // Build the stripped number (your exact logic, just left-to-right)
            if (digit != 0) {
                prefNum[i + 1] = (prefNum[i] * 10 + digit) % mod;
            } else {
                prefNum[i + 1] = prefNum[i];
            }
        }
        
        // 3. Answer all queries in O(1) time each!
        vector<int> arr;
        int q_size = queries.size();
        for (int i = 0; i < q_size; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            
            // Get sum of digits in range [left, right] instantly
            long long sum = prefSum[right + 1] - prefSum[left];
            
            // How many non-zero digits were inside this range?
            int count = nonZeroCount[right + 1] - nonZeroCount[left];
            
            // Extract the number formed by this substring instantly
            long long ans = prefNum[right + 1] - (prefNum[left] * power10[count]) % mod;
            
            // In C++, modulo subtraction can result in negative numbers, so we fix it:
            if (ans < 0) ans += mod;
            
            // Your exact final calculation:
            arr.push_back((1LL * ans * sum) % mod);
        }
        
        return arr;
    }
};