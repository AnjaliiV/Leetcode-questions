class Solution {
public:
    char dfs(char ch, vector<vector<char>> &adj, vector<bool>& visited) {
        visited[ch - 'a'] = true;

        char min_char = ch;

        for (char neigh : adj[ch - 'a']) {
            if (!visited[neigh - 'a']) {
                min_char = min(min_char, dfs(neigh, adj, visited));
            }
        }
        return min_char;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<vector<char>> adj(26);

        for (int i = 0; i < s1.size(); i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u - 'a'].push_back(v);
            adj[v - 'a'].push_back(u);
        }

        string res;

        for (char ch : baseStr) {
            vector<bool> visited(26, false);   
            char mini = dfs(ch, adj, visited);
            res.push_back(mini);
        }

        return res;
    }
};