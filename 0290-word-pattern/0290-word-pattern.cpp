class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // 1. Extract all words from the string separated by spaces
        while (ss >> word) {
            words.push_back(word);
        }
        
        // 2. If the lengths don't match, it can't be a valid pattern
        if (pattern.size() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar; 
        
        // 3. Iterate through the pattern and words simultaneously
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // Check if 'c' is already mapped to a DIFFERENT word
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            
            // Check if 'w' is already mapped to a DIFFERENT character
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }
            
            // Create the mapping for both directions
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        
        return true;
    }
};