class Disjointset{
    vector <int> parent,size;
public:
    Disjointset(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<n;i++){
            parent[i] = i;
        }
    }
    int findupar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int pu = findupar(u);
        int pv = findupar(v);

        if(pu == pv)return;
        if(size[pu] < size[pv]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int cntextra = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findupar(u) == ds.findupar(v)){
                cntextra++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(ds.findupar(i) == i)cnt++;
        }
        int ans = cnt-1;
        if(cntextra >= ans)return ans;
        return -1;
    }
};