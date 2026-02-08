#include<bits/stdc++.h>
using namespace std;
bool bfs(int st,vector<bool> &visited,vector<vector<int>> &adjrev,vector<bool> &badnode){
   visited[st]=1;
   queue<int> q;
   q.push(st);

   while(!q.empty()){
      int node=q.front();
      q.pop();
      if(badnode[node]){
         return true;
      }
      for(int neigh:adjrev[node]){
         if(!visited[neigh]){
            visited[neigh]=true;
            q.push(neigh);
         }
      }
   }
   return false;
}
int main(){
     int n,m;
     cin>>n>>m;
     vector<long long> dist(n+1,LLONG_MIN);
     dist[1]=0;
     vector<vector<int>> edges(m,vector<int>(3));
     for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=w;
     }
     for(int i=0;i<n-1;i++){
      for(auto &e:edges){
         int a=e[0];
         int b=e[1];
         int c=e[2];
         if(dist[a]==LLONG_MIN) continue;
         if(dist[b]<dist[a]+c){
            dist[b]=dist[a]+c;
         }
      }
     }

     vector<bool> badnode(n+1,0);
     bool check=false;
      for(auto &e:edges){
         int a=e[0];
         int b=e[1];
         int c=e[2];
         if(dist[a]==LLONG_MIN) continue;
         if(dist[b]<dist[a]+c){
            badnode[a]=true;
            check=true;
         }
      }

      if(check){
         vector<vector<int>> adjrev(n+1);
         vector<bool>visited(n+1,0);
         for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjrev[v].push_back(u);
         }
         if(bfs(n,visited,adjrev,badnode))
         cout<<"-1";
         else{
            cout<<dist[n];
         }

      }
      else{
         cout<<dist[n];
      }
}

