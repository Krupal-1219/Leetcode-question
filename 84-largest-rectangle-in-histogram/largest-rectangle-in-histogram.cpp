class Solution {
public:
    vector<int> getnse(vector <int> &arr){
        int n = arr.size();
        stack <int> st;
        vector <int> ans(n,0);
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);

        }
        return ans;
    }
    vector<int> getpsee(vector<int>& arr) {
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
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = getnse(heights);
        vector <int> pse = getpsee(heights);
        int maxi = 0;

        for(int i =0; i<heights.size(); i++ ){
            maxi = max(maxi, (nse[i]-pse[i] -1)*heights[i]);
        }
        return maxi;
    }
};