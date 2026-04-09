class Solution {
    // Helper function to calculate powers under a modulo
    int power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
    
    // Helper function to find the modular inverse using Fermat's Little Theorem
    int modInverse(int n) {
        return power(n, 1000000007 - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int MOD = 1000000007;
        
        // Our threshold for Square Root Decomposition (balances Time and Memory constraints)
        int T = min(n + 1, 200); 
        
        // diff[k][i] holds the multiplicative difference array for step size 'k'
        vector<vector<int>> diff(T, vector<int>(n, 1));
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], step = q[2], val = q[3];
            
            if (step >= T) {
                // LARGE STEPS: Safe to simulate directly because they skip over most elements
                for (int idx = l; idx <= r; idx += step) {
                    nums[idx] = (1LL * nums[idx] * val) % MOD;
                }
            } else {
                // SMALL STEPS: Use the Multiplicative Difference Array
                // Start applying the multiplication here
                diff[step][l] = (1LL * diff[step][l] * val) % MOD;
                
                // Calculate the exact index where the multiplication progression STOPS
                int count = (r - l) / step;
                int R = l + count * step + step; // The first index OUTSIDE the range
                
                // If the stop point is inside our array, apply the modular inverse to "cancel out" the multiplier
                if (R < n) {
                    long long inv = modInverse(val);
                    diff[step][R] = (1LL * diff[step][R] * inv) % MOD;
                }
            }
        }
        
        // Cascade and resolve all the small-step queries at once
        for (int k = 1; k < T; k++) {
            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    // Propagate the multiplication forward by 'k' steps
                    diff[k][i] = (1LL * diff[k][i] * diff[k][i - k]) % MOD;
                }
                // Apply the batched multipliers to the actual array
                if (diff[k][i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[k][i]) % MOD;
                }
            }
        }
        
        // Final calculation
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            xor_sum ^= nums[i];
        }
        
        return xor_sum;
    }
};