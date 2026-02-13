#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>visited(n,0);
    int minCost=0;
    // vector<pair<int,pair<int,int>>> path;
    vector<int>parent(n);

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});

    while(!pq.empty()){
        int node=pq.top().second.first;
        int cost=pq.top().first;
        int par=pq.top().second.second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=1;
        parent[node]=par;
        minCost+=cost;

        for(auto &p:adj[node]){
            int neigh=p.first;
            int c=p.second;
            if(!visited[neigh]){
                pq.push({c,{neigh,node}});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(parent[i]!=-1){
            cout<<parent[i]<< "-" <<i<<"\n";
        }
    }


}

