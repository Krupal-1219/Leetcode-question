class Solution {
public:
    // Renamed for clarity and to avoid variable shadowing
    vector<int> getNse(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // Renamed for clarity
    vector<int> getPsee(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); // FIXED: Added the missing push step
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = getNse(arr);
        vector<int> prevSmaller = getPsee(arr);
        
        long long total = 0; 
        long long mod = 1e9 + 7; // FIXED: Standard LeetCode modulo
        
        for (int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            
            // FIXED: Corrected syntax for large multiplications and typo
            long long contribution = (left * right) % mod;
            contribution = (contribution * arr[i]) % mod;
            
            total = (total + contribution) % mod;
        } 
        return total;  
    }
};