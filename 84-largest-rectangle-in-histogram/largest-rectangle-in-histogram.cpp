class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size(); 
        int max_area = 0;

        for (int i = 0; i <= n; i++) {
            // Use '0' as a sentinel value at the end (i == n) to flush the stack
            int current_height = (i == n) ? 0 : arr[i];
            
            // FIX: Compare arr[st.top()] instead of st.top()
            while (!st.empty() && arr[st.top()] > current_height) {
                int height = arr[st.top()];
                st.pop();
                
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                
                max_area = max(max_area, height * (nse - pse - 1));
            }
            st.push(i);
        }
        return max_area;
    }
};