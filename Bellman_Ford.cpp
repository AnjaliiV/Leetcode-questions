class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto &e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[u]!=1e8 &&dist[v]>dist[u]+w){
                return {-1};
            }
            
        }
        return dist;
    }
};
