class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    vector<int> quiet;

    int dfs(int node) {
        if (ans[node] != -1) return ans[node];   // memoized

        ans[node] = node; // assume node is quietest initially

        for (int neigh : adj[node]) {
            int candidate = dfs(neigh);
            if (quiet[candidate] < quiet[ans[node]]) {
                ans[node] = candidate;
            }
        }
        return ans[node];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quietInput) {
        int n = quietInput.size();
        quiet = quietInput;
        adj.resize(n);
        ans.assign(n, -1);

        // Build graph: v -> u (u is richer than v)
        for (auto &v : richer) {
            adj[v[1]].push_back(v[0]);
        }

        // Run DFS for each person
        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return ans;
    }
};