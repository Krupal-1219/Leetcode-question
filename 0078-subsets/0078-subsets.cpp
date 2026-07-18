class Solution {
public:
    void getallsubset(vector <int> &nums, vector<int>& subset , vector <vector<int>> &ans, int i){
        if (i == nums.size()){
            ans.push_back(subset);
            return;
        }
        // include 
        subset.push_back(nums[i]);
        getallsubset(nums, subset, ans, i+1);

        //exclude
        subset.pop_back();
        getallsubset(nums, subset, ans, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> subset;
        vector <vector<int>> ans;
        getallsubset(nums, subset, ans, 0);
        return ans;
    }
};