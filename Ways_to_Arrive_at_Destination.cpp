class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r:roads){
            int u=r[0];
            int v=r[1];
            int w=r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }
        vector<long long> dist(n,LLONG_MAX);
        vector<bool> final(n,0);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        int st=0;
        dist[st]=0;
        ways[st]=1;
        pq.push({0,st});

        while(!pq.empty()){
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            // if(final[node]) continue;
            // final[node]=1;
            if(weight>dist[node]) continue;

            for(auto &neigh:adj[node]){
                int v=neigh.first;
                int w=neigh.second;
                if(dist[node]+w<dist[v]){
                    dist[v]=dist[node]+w;
                    ways[v]=ways[node];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==dist[node]+w){
                    ways[v]=(ways[node]+ways[v]) % MOD;
                }

            }
        }
        return ways[n-1]%MOD;


        
    }
};