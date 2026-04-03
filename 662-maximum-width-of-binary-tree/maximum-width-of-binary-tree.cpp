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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = 0;
        // Use long long for the index to prevent integer overflow
        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            long long min_value = q.front().second; // minimum index at current level
            long long first = 0, last = 0;
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                // Normalize the index to start from 0 for each level
                long long curr_idx = q.front().second - min_value; 
                q.pop();
                
                if(i == 0) first = curr_idx;
                if(i == size - 1) last = curr_idx;
                
                // 2 * curr_idx will now safely fit inside a long long
                if(node->left) q.push({node->left, 2 * curr_idx + 1});
                if(node->right) q.push({node->right, 2 * curr_idx + 2});
            }
            // Moved outside the loop: Update the max width once per level
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        
        return ans;
    }
};