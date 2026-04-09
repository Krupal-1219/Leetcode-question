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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap; 
        
        // Map inorder values to their indices for O(1) lookup
        for(int i = 0; i < inorder.size(); i++) { 
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inmap);
        return root;
    }
    
    TreeNode* helper(vector<int>& inorder, int instart, int inend, 
                     vector<int>& postorder, int poststart, int postend, 
                     unordered_map<int, int>& inmap) {
        
        // Base case: if pointers cross, we've gone past the leaf nodes
        if(instart > inend || poststart > postend) return NULL;
        
        // In postorder, the root is always at the END of the current segment
        TreeNode* root = new TreeNode(postorder[postend]); 
        
        // Find the root in the inorder map to calculate left/right subtree sizes
        int inroot = inmap[root->val];
        int numsleft = inroot - instart;
        
        // Recursively build left and right subtrees
        // Left subtree uses the first 'numsleft' elements in postorder
        root->left = helper(inorder, instart, inroot - 1, 
                            postorder, poststart, poststart + numsleft - 1, inmap);
                            
        // Right subtree uses the remaining elements before the root in postorder
        root->right = helper(inorder, inroot + 1, inend, 
                             postorder, poststart + numsleft, postend - 1, inmap);
        
        return root;
    }
};