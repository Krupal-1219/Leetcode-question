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
    bool isValidBST(TreeNode* root) {
        long long int maxvalue = LLONG_MAX;
        long long int minvalue = LLONG_MIN;
       return isbsttravelsal(root, maxvalue, minvalue);
    }
    bool isbsttravelsal(TreeNode* node, long long int maxvalue, long long int  minvalue){
        if (node == NULL)return true;
        if(node->val <= minvalue || node->val >= maxvalue)return false;
        return isbsttravelsal(node->left, node->val, minvalue) && isbsttravelsal(node->right,maxvalue , node->val);

    }

};