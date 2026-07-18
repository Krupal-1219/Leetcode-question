class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Variable to store XOR of all elements
        long XOR = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            // Update the XOR
            XOR = XOR ^ nums[i];
        }
        
        /* Variable to get the rightmost 
        set bit in overall XOR */
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        
        /* Variables to stores XOR of
        elements in bucket 1 and 2 */
        int XOR1 = 0, XOR2 = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
        
        // Return the result in sorted order
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};