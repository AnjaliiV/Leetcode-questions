class Solution {
public:
    bool dfs(int n,vector<vector<int>> &adj,vector<bool> &visited,int dest){
        visited[n]=1;
        if(n==dest) return true;

        for(int i:adj[n]){
            if(!visited[i]){
                if(dfs(i,adj,visited,dest)){
                    return true;
                }
            }  
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,0);
        return dfs(source,adj,visited,destination);
    
    }
};