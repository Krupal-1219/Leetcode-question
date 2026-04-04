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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        queue<TreeNode*> q;
        q.push(root);
        
        // Convert Tree to Graph
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if (node->right) {
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        
        // BFS to find max distance (time to infect)
        queue<int> infectionQueue;
        unordered_map<int, bool> visited;
        infectionQueue.push(start);
        visited[start] = true;
        
        int minutes = 0;
        while (!infectionQueue.empty()) {
            int size = infectionQueue.size();
            for (int i = 0; i < size; i++) {
                int current = infectionQueue.front();
                infectionQueue.pop();
                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        infectionQueue.push(neighbor);
                    }
                }
            }
            if (!infectionQueue.empty()) {
                minutes++;
            }
        }
        
        return minutes;
    }
};