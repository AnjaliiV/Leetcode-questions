class Solution {
public:
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            unionSet(u,v);
        }
        vector<int>componentSize(n,0);
        for(int i=0;i<n;i++){
            int root=find(i);
                componentSize[root]++;
        }

        long long ans=0;
        long long remaining=n;
        for(int i=0;i<n;i++){
            ans+=componentSize[i]*(remaining-componentSize[i]);
            remaining-=componentSize[i];

        }
        return ans;
    }
};