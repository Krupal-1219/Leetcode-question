class Solution {
public:
    void solve(int idx, int target, int n, vector<int>& v, set<vector<int>>& st, vector<int>&candidates ){
        if(idx == n || target<0){
            return;
        }
        if(target == 0){
            st.insert(v);
            return;
        }
        solve(idx+1,target,n,v,st,candidates);

        v.push_back(candidates[idx]);

        solve(idx,target-candidates[idx],n,v,st,candidates);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set <vector<int>> st;
        vector <int> v;
        int idx = 0;
        int n = candidates.size();
        solve(idx,target,n,v,st,candidates);

        vector <vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};