class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V,0);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            indegree[v]++;
            
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int  node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &p:adj[node]){
                int neigh=p.first;
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
            
        }
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        
        for(int node:ans){
            if(dist[node]==INT_MAX)
            continue;
            for(auto &p:adj[node]){
                int neigh=p.first;
                int w=p.second;
                dist[neigh]=min(dist[neigh],dist[node]+w);
                
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
