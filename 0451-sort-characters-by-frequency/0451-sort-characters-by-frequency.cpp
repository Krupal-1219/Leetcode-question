class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> mpp;

        for(int i =0 ;i<s.size();i++){
            mpp[s[i]] ++;
        }

        priority_queue<pair<int,char>> pq;
        string ans = "";
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            int cnt = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            ans.append(cnt,c);
            
        }
        return ans;
    }
};