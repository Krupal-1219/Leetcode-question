class Solution {
public:
    int largestRectangle(vector<int>& arr) {
        // Write your code here.
        stack<int> st;
        int maxarea = 0;
        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int idx = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea , arr[idx]*(nse-pse-1));
            } 
            st.push(i);
        }
        while(!st.empty()){
            int nse = arr.size();
            int idx = st.top();
            st.pop();
            int pse = st.empty() ? -1: st.top();
            maxarea = max(maxarea, arr[idx]*(nse-pse-1));
        }
        return maxarea; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // FIXED: Added a quick check to prevent a crash if the matrix is completely empty
        if(matrix.empty()) return 0; 
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // FIXED: Properly initialized the 2D vector with dimensions and 0s
        vector<vector<int>> psum(n, vector<int>(m, 0)); 
        int max_area = 0;
        
        for(int j = 0; j<m;j++){
            int sum =0;
            for(int i = 0;i<n;i++){
                // FIXED: Compared against the character '0', and safely added 1 if it's a '1'
                if(matrix[i][j] == '0') sum = 0;
                else sum += 1; 
                
                psum[i][j] = sum;
            }
        }
        for (int i = 0; i<n;i++){
            max_area = max(max_area,largestRectangle(psum[i]) );
        } 
        return max_area;
    }
};