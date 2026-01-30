class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool> isFinalized(V,0);
        vector<int> dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int st=src;
        dis[st]=0;
        pq.push({dis[st],st});

        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(isFinalized[node])
            continue;
            isFinalized[node]=1;
            
            for(auto &neigh:adj[node]){
                int v=neigh.first;
                int w=neigh.second;
                
                if(dis[v]>dis[node]+w &&!isFinalized[v]){
                    dis[v]=dis[node]+w;
                    pq.push({dis[v],v});
                }
            }
            
        }
        return dis;
    }
};