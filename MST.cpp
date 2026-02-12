class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<bool>visited(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int minCost=0;
        pq.push({0,0});
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node]=1;
            minCost+=cost;

            for(auto &p:adj[node]){
                int neigh=p.first;
                int c=p.second;
                if(!visited[neigh]){
                    pq.push({c,neigh});
                }
            }
        }
        return minCost;
    }
};