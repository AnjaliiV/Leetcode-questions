// class Solution {
// public:
//     bool dfs(int u, vector<bool> &visited, vector<bool> &path, 
//         stack<int> &s, vector<vector<int>> &adj) {
//         visited[u] = true;
//         path[u] = true;

//         for (int neigh : adj[u]) {
//             if (!visited[neigh]) {
//                 if (!dfs(neigh, visited, path, s, adj))
//                     return false;
//             } 
//             else if (path[neigh]) {
//                 return false; // cycle found
//             }
//         }

//         path[u] = false;
//         s.push(u);
//         return true;
//     }

//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for (auto &p : prerequisites) {
//             adj[p[1]].push_back(p[0]);
//         }

//         vector<bool> visited(numCourses, false), path(numCourses, false);
//         stack<int> s;

//         for (int i = 0; i < numCourses; i++) {
//             if (!visited[i]) {
//                 if (!dfs(i, visited, path, s, adj))
//                     return {};  
//             }
//         }

//         vector<int> ans;
//         while (!s.empty()) {
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;
//     }
// };
// BFS:
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        queue<int> q;
        int V=numCourses;
        vector<int> Indegree(V,0);
        vector<vector<int>> adj(V);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            for(int &neigh:adj[i]){
                Indegree[neigh]++;
            }
        }
        for(int i=0;i<V;i++){
             if(Indegree[i]==0){
                 q.push(i);
             }

        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int &neigh:adj[node]){
                Indegree[neigh]--;
                if(Indegree[neigh]==0){
                    q.push(neigh);

                }
            }
        }
        if(ans.size()!=V) return {};
        return ans;

    }
};