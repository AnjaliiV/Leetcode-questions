#include<bits/stdc++.h>
using namespace std;
int dfs(int st,vector<vector<int>> &adj,vector<bool> &visited,int n,int m,vector<int> &isCat,int con_cat,int &count){
    visited[st]=1;
    if(isCat[st]==1){
        con_cat++;
    }
    else{
        con_cat=0;
    }
    bool isleaf=1;
    if(con_cat>m) return 0;
    for(auto &neigh:adj[st]){
        if(!visited[neigh]){
            isleaf=false;
            dfs(neigh,adj,visited,n,m,isCat,con_cat,count);
        }
    }
    if(isleaf) count++;
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,0);
    vector<int> isCat(n+1);
    int count=0;

    for(int i=1;i<=n;i++){
        cin>>isCat[i];
    }
    for(int i=0;i<=n-1;i++){
        int u;
        int v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,adj,visited,n,m,isCat,0,count);
    cout<<count;
    return 0;

}