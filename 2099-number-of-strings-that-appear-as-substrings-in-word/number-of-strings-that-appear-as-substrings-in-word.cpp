class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string s:patterns){
            for(int i = 0 ;i<word.size(); i++){
                if(word.substr(i,s.size()) == s){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};