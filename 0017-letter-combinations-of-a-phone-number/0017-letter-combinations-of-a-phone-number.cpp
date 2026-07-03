class Solution {
public:
    // FIX 1: Passed 'ans', 'digits', and 'mpp' by reference (&) to avoid making expensive copies.
    // 'ans' MUST be passed by reference so the main function sees the added combinations.
    void backtrack(const string& digits, vector<string>& ans, const vector<string>& mpp, int idx, string comb) {
        // base case
        if (idx == digits.size()) {
            ans.push_back(comb);
            return;
        } 
        
        // FIX 2: digits[idx] is a 'char' (like '2'), not a 'string'.
        char digit = digits[idx];
        
        // FIX 3: Convert the char to an integer index (e.g., '2' - '0' = 2) to lookup in our vector
        string letters = mpp[digit - '0'];
        
        for (char it : letters) {
            backtrack(digits, ans, mpp, idx + 1, comb + it);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        
        // FIX 4: Replaced unordered_map with a simple vector. It is MUCH faster for indexing 0-9.
        // Index 0 and 1 are empty strings. Index 2 holds "abc", etc.
        vector<string> mpp = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> res;
        backtrack(digits, res, mpp, 0, "");
        return res;
    } 
};