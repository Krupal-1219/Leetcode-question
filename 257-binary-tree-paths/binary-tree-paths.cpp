
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
       if(root==NULL)return {};
       if(root->left==NULL&&root->right==NULL){
        return {to_string(root->val)};
       }
       vector<string>ans;
       vector<string>leftpath = binaryTreePaths(root->left);
       for(string s:leftpath){
        ans.push_back(to_string(root->val)+"->"+s);
       }
       vector<string>rightpath = binaryTreePaths(root->right);
       for(string s: rightpath){
        ans.push_back(to_string(root->val)+"->"+s);
       }
       return ans;
    }
};