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
    int path(TreeNode* node, int& maxi){
        if (node == NULL)return 0;

        int leftsum = max(0, path(node->left,maxi));
        int rightsum = max(0, path(node->right, maxi));

        maxi = max(maxi, node->val + leftsum + rightsum);
        return node->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }
};