/*class Solution {
public:
vector<int> par,rank;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    bool unionSet(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return false;

        if(rank[pa]==rank[pb]){
            par[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]>rank[pb]){
            par[pb]=pa;
        }
        else{
            par[pa]=pb;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        rank.assign(n+1,0);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        vector<int>ans;
        for(auto &e:edges){
            if(!unionSet(e[0],e[1])){
                ans.push_back(e[0]);
                ans.push_back(e[1]);
            }
        
        }
        return ans;
    }
};*/
class Solution {
public:
vector<int> par,rank;
vector<int> ans;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unionSet(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) {
            ans.push_back(a);
            ans.push_back(b);
            return;
        }
        

        if(rank[pa]==rank[pb]){
            par[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]>rank[pb]){
            par[pb]=pa;
        }
        else{
            par[pa]=pb;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        rank.assign(n+1,0);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(auto &e:edges){
            unionSet(e[0],e[1]);
        
        }
        return ans;
    }
};