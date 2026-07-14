class Solution {
private:
    bool fn(int i, int j, int len, string &s, string &p, vector<vector<int>>&dp){
        if(len==s.length() && i==s.length() && j==p.length()) return true;
        if(j==p.length()) return false;
        if(i==s.length()){
            for(int k=j; k<p.length(); k++){
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j]=='*'){
            return dp[i][j]=fn(i,j+1,len,s,p,dp) || fn(i+1,j,len+1,s,p,dp);
        }

        else if(i<s.length() && (s[i]==p[j] || p[j]=='?')){
            return dp[i][j]=fn(i+1,j+1,len+1,s,p,dp);
        }

        return dp[i][j]=false;
        
        
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+2,vector<int>(p.length()+2,-1));
        return fn(0,0,0,s,p,dp);
    }
};