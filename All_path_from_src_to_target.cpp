class Solution {
public:
int n;
    void dfs(int st,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int> &path){
        path.push_back(st);

        if(st==n-1) ans.push_back(path);
        else{
          for(auto &v:graph[st]){
                dfs(v,graph,ans,path);
           }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0,graph,ans,path);

        return ans;
        
    }
};