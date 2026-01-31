class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       vector<vector<int>> ancestor(n);
       for(int i=0;i<edges.size();i++){
        int node=edges[i][0];
        int v=edges[i][1];
        adj[node].push_back(v);
       } 
       vector<int>Indegree(n,0);
       for(int i=0;i<n;i++){
             for(int neigh:adj[i]){
                Indegree[neigh]++;
             }
       }
       queue<int> q;
       vector<int> ans;
       for(int i=0;i<n;i++){
        if(Indegree[i]==0){
            q.push(i);
        }
       }

       while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int neigh:adj[node]){
            Indegree[neigh]--;
            if(Indegree[neigh]==0){
                q.push(neigh);
            }
        }
       }

       vector<set<int>> vec(n);
       for(int node:ans){
        for(int neigh:adj[node]){
            vec[neigh].insert(node);
            vec[neigh].insert(vec[node].begin(),vec[node].end());
        }
       }
       for(int i=0;i<n;i++){
        ancestor[i]=vector<int>(vec[i].begin(),vec[i].end());
        sort(ancestor[i].begin(),ancestor[i].end());

       }
       return ancestor;

    }
};