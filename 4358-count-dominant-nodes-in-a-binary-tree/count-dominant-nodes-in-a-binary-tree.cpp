/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode * root){
        if(root == NULL)return INT_MIN;
        int leftmax = solve(root->left);
        int rightmax = solve(root->right);

        int maxi = max(root->val,max(leftmax,rightmax));
        if(maxi == root->val)res++;
        return maxi;
    }
public:
int res = 0;    
    int countDominantNodes(TreeNode* root) {
       res = 0; 
        solve(root);
        return res;
    }

};