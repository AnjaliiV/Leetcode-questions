#include<bits/stdc++.h>
using namespace std;
void dfs(int st,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &s){
    visited[st]=1;

    for(int neigh:adj[st]){
        if(!visited[neigh]){
            dfs(neigh,adj,visited,s);
        }
    }
    s.push(st);
}

void revDfs(int st,vector<vector<int>> &revAdj,vector<bool> &visited,vector<int> &sol,int kingdom){
    visited[st]=1;
    sol[st]=kingdom;
    for(int neigh:revAdj[st]){
        if(!visited[neigh]){
            revDfs(neigh,revAdj,visited,sol,kingdom);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u;
        int v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool>visited(n+1,0);
    stack<int>s;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }

    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    vector<vector<int>> revAdj(n+1);
    for(int i=1;i<=n;i++){
        for(int v:adj[i]){
            revAdj[v].push_back(i);
        }
    }
    vector<int> sol(n+1,0);
    int kingdom=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited[node]){
            kingdom++;
            revDfs(node,revAdj,visited,sol,kingdom);
        }
    }
    cout<< kingdom<<"\n";  
      
    for(int i=1;i<=n;i++){
        cout<<sol[i]<<" ";
    }
}
