/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Fix 3: Upgraded to unordered_map for O(1) lookups
        unordered_map<int, int> inmap; 
        
        // Fix 1: Changed '<<' to '<'
        for(int i = 0; i < inorder.size(); i++){ 
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
        return root;
    }
    
    // Fix 3: Passed 'inmap' by reference (&)
    TreeNode* helper(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int, int>& inmap) {
        if(prestart > preend || instart > inend) return NULL;
        
        // Fix 2: Changed 'Prestart' to 'prestart'
        TreeNode* root = new TreeNode(preorder[prestart]); 
        
        int inroot = inmap[root->val];
        int numsleft = inroot - instart;
        
        root->left = helper(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, inmap);
        root->right = helper(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, inmap);
        
        return root;
    }
};