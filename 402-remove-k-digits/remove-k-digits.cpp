class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        
        stack<char> st;
        for(int i = 0; i < n; i++) {
            // FIXED: Simplified character comparison. '9' > '5' evaluates perfectly without math.
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k = k - 1;
            }
            st.push(num[i]);
        }
        
        // FIXED: Added !st.empty() to prevent a crash if the stack runs out of items
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        
        if(st.empty()) return "0"; 
        
        string ans = "";
        
        // FIXED: Replaced the clunky for-loop with a clean while-loop and used += for efficiency
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        } 
        
        while(ans.size() != 0 && ans.back() == '0') {
            ans.pop_back();
        }
        
        // FIXED: Passed correct iterators to the reverse function
        reverse(ans.begin(), ans.end());
        
        if(ans.empty()) return "0";
        
        return ans;
    }
};