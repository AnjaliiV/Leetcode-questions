class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights){
            int u=f[0];
            int v=f[1];
            int w=f[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        dist[src]=0;
        q.push({0,{src,0}});
        
        
        while(!q.empty()){
            int cost=q.front().first;
            int node=q.front().second.first;
            int stops=q.front().second.second;
            q.pop();
            
            if(stops>K) continue;
            
            for(auto &p:adj[node]){
                int neigh=p.first;
                int c=p.second;
                if(dist[neigh]>cost+c){
                    dist[neigh]=cost+c;
                    q.push({dist[neigh],{neigh,stops+1}});
                }
            }
            
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
        
    }
};