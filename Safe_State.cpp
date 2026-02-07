class Solution {
public:
   bool dfs(int st,vector<vector<int>>& graph,vector<int> &state){
    if(state[st]!=0) return state[st]==2; //safe

    state[st]=1;

    for(auto &neigh:graph[st]){
        if(!dfs(neigh,graph,state)){
             return false;  //cycle detected
        }
    }
    state[st]=2;
    return true;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> state(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(dfs(i,graph,state)){
                ans.push_back(i);
            }
        }  
        return ans;
    }
};
