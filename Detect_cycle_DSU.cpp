class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    
    void unionSet(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return;
        
        if(rank[pa]==rank[pb]){
            parent[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        }
        else{
            parent[pa]=pb;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
        rank.assign(V,0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                if(u<v){
                    int pu=find(u);
                    int pv=find(v);
                    if(pu==pv) return 1;
                }
                unionSet(u,v);
            }
        }
        return 0;
    }
};