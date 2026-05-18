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
    int cnt = 0;   // must be global/member so it persists across recursive calls

    TreeNode* inorder(TreeNode* node, int k) {
        if (node == nullptr) {
            return nullptr;
        }

        // Search in left subtree
        TreeNode* leftResult = inorder(node->left, k);
        if (leftResult != nullptr) {
            return leftResult;
        }

        // Visit current node
        cnt++;
        if (cnt == k) {
            return node;
        }

        // Search in right subtree
        return inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        cnt = 0; // reset counter for each test case
        TreeNode* resNode = inorder(root, k);
        return resNode->val;
    }
};