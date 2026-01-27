class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj,vector<bool>&visited,vector<bool>&inRecursion){
        visited[u]=1;
        inRecursion[u]=1;
        for(int neigh:adj[u]){
            if(!visited[neigh] && dfs(neigh,adj,visited,inRecursion)) return true; //cycle found cannot finish
            else if(inRecursion[neigh]) {
                return true;
            }
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<bool> visited(numCourses,0);
        vector<bool> inRecursion(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(i,adj,visited,inRecursion)){
                return false;
            }
        }
        return true;

    }
};