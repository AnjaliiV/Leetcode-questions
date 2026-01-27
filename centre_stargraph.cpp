// class Solution {
// public:
// void helper(int u,vector<vector<int>> &adj,vector<bool> &visited){
//     visited[u]=true;
//     for(int neigh:adj[u]){
//         if(!visited[neigh]) 
//         dfs(neigh,adj,visited);
//     }
// }
//     int findCenter(vector<vector<int>>& edges) {
//         int v;
//         vector<vector<int>> adj(v+1,0);
//         for(auto &e:edges){
//             adj[e[0]].push_back(e[1]);
//         }
//         vector<bool> visited(v+1,0);
//         return dfs(v,adj,visited);
//         for(int i=0;i<v;i++){
//             if(visited==false) return -1;
//             return i;
//         }
        
//     }
// };
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> degree(n+1,0);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            degree[u]++;
            degree[v]++;
        }
        for(int i=1;i<=n;i++){
            if(degree[i]==n-1)
            return i;
        }
        return -1;
    }
};