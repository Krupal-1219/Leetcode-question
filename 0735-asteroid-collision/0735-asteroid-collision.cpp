class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        
        for(int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                // Keep popping while the top is moving right (positive) 
                // AND is smaller than the current left-moving asteroid
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]) {
                    st.pop();
                }
                
                // If they are exactly the same size, they both explode
                if (!st.empty() && st.top() == -asteroids[i]) {
                    st.pop();
                }
                // If the stack is empty, or the top asteroid is ALSO moving left, 
                // it's safe to push the current negative asteroid
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }
        
        // Properly size the result vector before inserting elements
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};