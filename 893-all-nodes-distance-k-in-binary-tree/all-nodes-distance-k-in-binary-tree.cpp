class Solution {
public:
    void mark_parents(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_check){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parent_check[current->left] = current;
            }
            if(current->right){
                q.push(current->right);
                parent_check[current->right] = current;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode* , TreeNode*> parent_check;
        mark_parents(root, parent_check);

        unordered_map <TreeNode* , bool> visited;
        queue <TreeNode*> q;
        q.push(target);
        int dist = 0;
        visited[target] = true;
        
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_check[current] && !visited[parent_check[current]]){
                    q.push(parent_check[current]);
                    // FIX: Added "= true" to correctly mark the parent as visited
                    visited[parent_check[current]] = true; 
                }
            }
            // FIX: Increment distance after finishing the current level
            dist++; 
        }
        
        vector<int> ans;
        while(!q.empty()){
            TreeNode* current = q.front(); 
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};