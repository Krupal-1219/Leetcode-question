class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word,
             string beginWord,
             vector<string>& path) {

        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(auto &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(!dict.count(endWord))
            return {};

        unordered_map<string,int> dist;

        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;

        while(!q.empty()) {

            string word = q.front();
            q.pop();

            int steps = dist[word];

            string temp = word;

            for(int i = 0; i < temp.size(); i++) {

                char original = temp[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if(!dict.count(temp))
                        continue;

                    if(!dist.count(temp)) {

                        dist[temp] = steps + 1;
                        q.push(temp);

                        parent[temp].push_back(word);
                    }
                    else if(dist[temp] == steps + 1) {

                        parent[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if(!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};