#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> final(n+1,0);
    vector<int> parent(n+1);
    vector<int> dist(n+1,INT_MAX);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int st=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[st]=0;
    parent[st]=0;
    pq.push({dist[st],st});
    while(!pq.empty()){
        int curDist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(final[node])
        continue;
        final[node]=1;

        for(auto &neigh:adj[node]){
            int v=neigh.first;
            int wt=neigh.second;

            if(!final[v] && dist[v]>dist[node]+wt){
                dist[v]=dist[node]+wt;
                parent[v]=node;
                pq.push({dist[v],v});
            }
        }
    }

    //extra other than dijkstra:
    if(dist[n]==INT_MAX)
    cout<<-1;
    else{        
        vector<int> path;
        int cur = n;
        while(cur != 0){           
            path.push_back(cur);
            cur = parent[cur];      
        }
        reverse(path.begin(), path.end());
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }

}
