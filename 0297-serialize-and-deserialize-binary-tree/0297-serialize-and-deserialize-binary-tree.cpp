/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // FIX 2: Handle empty tree edge case immediately
        if (root == NULL) return ""; 

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(node->val) + ',');
            }
            if(node != NULL ){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // This now perfectly catches the empty string returned by our fixed serialize()
        if(data.size() == 0) return NULL; 
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop(); // Note: added q.pop() here, you missed this in your deserialize while loop!
            
            getline(s, str, ',');
            // FIX 1: Use double quotes for string comparison
            if(str == "#"){ 
                node->left = NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            
            getline(s, str, ',');
            // FIX 1: Use double quotes for string comparison
            if(str == "#"){ 
                node->right = NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};