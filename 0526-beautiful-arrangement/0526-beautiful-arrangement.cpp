class Solution {
public:
    void solve(vector <int>&v, int idx, int& ans){
        if(idx == v.size()){
            ans++;
            return;
        }
        for(int i = idx; i<v.size();i++){
            if(v[i]%(idx+1) == 0 || (idx+1)%v[i] == 0){
                swap(v[idx],v[i]);
                solve(v,idx+1,ans);
                swap(v[i], v[idx]);
            }
        }
    }
    int countArrangement(int n) {
       vector <int> v;
       int ans = 0;
       for(int i =1;i<=n;i++){
            v.push_back(i);
       } 
       solve(v,0,ans);
       return ans;
    }
};