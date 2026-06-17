class Disjointset{
    vector <int> parent,size;
public:
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i<=n;i++){
            parent[i] =i;
        }
    }
    int findupar(int node){
        if(node == parent[node])return node;
        // path compression 
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int pu = findupar(u);
        int pv = findupar(v);
        if(pu == pv)return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjointset ds(n);
        unordered_map <string, int> mpp;
        for(int i = 0; i<n;i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionbysize(i,mpp[mail]);
                }
            }
        }
        vector <string> mergedmail[n];
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findupar(it.second);
            mergedmail[node].push_back(mail);
        }
        vector <vector <string>> ans;
        for(int i = 0 ;i<n;i++){
            if(mergedmail[i].size() == 0)continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector <string> temp;
            
            temp.push_back(accounts[i][0]);
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};