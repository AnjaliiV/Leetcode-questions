class Solution {
public:
   vector<int>par,rank;

   int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
   }

   void unionSet(int a,int b){
    int pa=find(a);
    int pb=find(b);
    if(pa==pb) return;

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

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }     
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                unionSet(i,i+1);
            }
        }
        vector<bool>ans;
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];
            ans.push_back(find(u)==find(v));
        }
        return ans;
   
    }
};