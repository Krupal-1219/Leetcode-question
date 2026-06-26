/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return root;
        queue<pair<int,Node*>> q;
        q.push({1,root});
        while(!q.empty()){
            int n  = q.size();
            while(n--){
                Node* curr = q.front().second;
                int level = q.front().first;
                q.pop();
                if(!q.empty() && level == q.front().first){
                    curr->next = q.front().second;
                }
                else if(q.empty())curr->next = NULL;

                if(curr->left)q.push({level+1, curr->left});
                if(curr->right)q.push({level+1,curr->right});
            }
        }
        return root;
    }
};