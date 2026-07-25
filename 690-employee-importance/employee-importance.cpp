/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>imp;
        for(auto i:emp){
            imp[i->id]=i->importance;
            for(auto v:i->subordinates){
                mp[i->id].push_back(v);
            }
        }
        int ans=0;
        queue<int>q;
        q.push(id);
        while(!q.empty()){
            int c=q.front();
            q.pop();
            ans+=imp[c];
            for(auto i:mp[c]){
                q.push(i);
            }
        }
        return ans;
    }
};