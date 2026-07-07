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
public:
    int dfs(TreeNode* node, TreeNode* root){
        if(node == NULL)return -1;
        if(node->val > root->val)return node->val;
        int  left = dfs(node->left,root);
        int right = dfs(node->right,root);
        if(left == -1)return right;
        if(right == -1)return left;
        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root);
    }
};