class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l =0;
        int r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        while(l<m && r<n){
            if(g[r] <= s[l])r++;
            l++;
        }
        return r;
    }
};