#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>visited(n+1,0);
    priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
    long long minCost=0;
    pq.push({0,1});
    // int count=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        minCost+=cost;
        visited[node]=1;
        // count++;

        for(auto &a:adj[node]){
            int v=a.first;
            int c=a.second;
            if(!visited[v]){
                pq.push({c,v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<minCost;
    // if(count!=n){
    //     cout<<"IMPOSSIBLE";
    // }
    // else{
    //     cout<<minCost;
    // }
    

}
