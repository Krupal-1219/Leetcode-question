class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> ans = arr;
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for(int i = 0;i<arr.size();i++){
            arr[i] = lower_bound(ans.begin(),ans.end(), arr[i] )-ans.begin()+1;
        }
        return arr;
    }
};