class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        if(s.size() == 0) return t[0];

        for(auto it : s){
            ans = ans^it;
        }
        for(auto it : t ){
            ans = ans^it;
        }
        return ans;
    }
};