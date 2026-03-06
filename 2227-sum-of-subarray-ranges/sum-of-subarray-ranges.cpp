class Solution {
public:
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

    vector<int> getPsee(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return ans;
    }

    long long  sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = getNse(arr);
        vector<int> prevSmaller = getPsee(arr);
        
        long long total = 0; 
        
        
        for (int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            long long contribution = (left * right) ;
            contribution = (contribution * arr[i]) ;
            
            total = (total + contribution) ;
        } 
        return total;  
    }
    vector<int> getNge(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> getPgee(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return ans;
    }

    long long  sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = getNge(arr);
        vector<int> prevSmaller = getPgee(arr);
        
        long long total = 0; 
      
        
        for (int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            long long contribution = (left * right) ;
            contribution = (contribution * arr[i]) ;
            
            total = (total + contribution) ;
        } 
        return total;  
    }
    long long subArrayRanges(vector<int>& arr) {
       return sumSubarrayMaxs(arr) - sumSubarrayMins(arr); 
    }
};