#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int>rnk;
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

bool unionSet(int a,int b){
    int pa=find(a);
    int pb=find(b);
    if(pa==pb) return false; //cycle

    if(rnk[pa]==rnk[pb]){
        parent[pb]=pa;
        rnk[pa]++;
    }
    else if(rnk[pa]>rnk[pb]){
        parent[pb]=pa;
    }
    else{
        parent[pa]=pb;
    }
    return true;
}

int main(){
    int n,m;
    cin>>n;
    m=n-1;
    parent.resize(n+1);
    rnk.assign(n+1,0);

    vector<pair<int,int>>path;

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(!unionSet(u,v)){
            path.push_back({u,v});
        }
    }

    vector<int> count;
    for(int i=1;i<=n;i++){
        if(find(i)==i)
        count.push_back(i);
    }
    cout<<count.size()-1<<"\n";

    for(int i=1;i<count.size();i++){
        cout<<path[i-1].first<<" "<<path[i-1].second<<" "<<count[0]<<" "<<count[i]<<"\n";
    }
}