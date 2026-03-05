class Solution {
public:
    // Helper function to find Next Greater Element for all elements in nums2
    vector<int> nge(vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> ans(n2); // Replaced array with vector
        stack<int> s;        // Standardized the stack name to 's'
        
        for (int i = n2 - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = s.top();
            }
            s.push(nums2[i]); // Standardized stack name
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        int n1 = nums1.size();
        
        vector<int> NGE = nge(nums2); // Changed 'int' to 'vector<int>'
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n2; i++) {
            mpp[nums2[i]] = NGE[i]; // Fixed 'nums' typo to 'nums2'
        }
        
        vector<int> result(n1); // Replaced array with vector
        for (int i = 0; i < n1; i++) {
            result[i] = mpp[nums1[i]];
        }
        return result;
    }
};