/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* node , vector <int>& ans){
        if(node == NULL)return;
        for(auto child : node->children){
            dfs(child, ans);
            ans.push_back(child->val);
        }
    }
    vector<int> postorder(Node* root) {
        if(root == NULL)return {};
        vector <int> ans;
        dfs(root, ans);
        ans.push_back(root->val);
        return ans;

    }
};