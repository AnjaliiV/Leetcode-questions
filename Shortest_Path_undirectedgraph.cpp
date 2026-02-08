class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(V,0);
        vector<int> dist(V,-1);
        
        queue<int> q;
        visited[src]=1;
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int neigh:adj[node]){
                if(dist[neigh]==-1 ){
                    dist[neigh]=dist[node]+1;
                    visited[neigh]=1;
                    q.push(neigh);
                }
            }
        }
        

        return dist;
    }
};
