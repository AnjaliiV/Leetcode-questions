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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &p:pairs){
            int u=p[0];
            int v=p[1];
            unionSet(u,v);
        }
        vector<vector<int>> component(n);
        for(int i=0;i<n;i++){
            component[find(i)].push_back(i);
        }
        for(int i=0;i<component.size();i++){
            vector<int> idx=component[i];
            string temp="";
            for(auto &x:idx){
                temp.push_back(s[x]);
            }
            sort(temp.begin(),temp.end());
            for(int j=0;j<idx.size();j++){
                s[idx[j]]=temp[j];
            }
        }
        return s;
    }
};