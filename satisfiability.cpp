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
    bool equationsPossible(vector<string>& equations) {
        // int n=string.size();
        parent.resize(26);
        rank.assign(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(auto &e:equations){
            if(e[1]=='='){
                int u=e[0]-'a';
                int v=e[3]-'a';
                unionSet(u,v);
            }
        }
        for(auto &e:equations){
            if(e[1]=='!'){
                int u=e[0]-'a';
                int v=e[3]-'a';
                if(find(u)==find(v))
                return false;
            }
        }
        return true;

    }
};