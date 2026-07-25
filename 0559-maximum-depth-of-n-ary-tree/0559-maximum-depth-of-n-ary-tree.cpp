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
int solve(Node* root){
    if(!root)return 0;
    int maxLevel = 0;

    //recur among child max level
    for(Node* next : root->children){
        int childLevel = solve(next);
        maxLevel = max(maxLevel, childLevel);
    }
    return maxLevel + 1;
}
    int maxDepth(Node* root) {
        
        if(!root)return 0;
        return solve(root);
    }
};