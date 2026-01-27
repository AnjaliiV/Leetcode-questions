// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<vector<int>> adj(n+1);
//         for(auto &e:trust){
//             adj[e[0]].push_back(e[1]);
//         }

//         //indegree for each vertex n:
//         vector<int> inDegree(n+1,0);
//         for(int i=1;i<=n;i++){
//             for(int &neigh:adj[i]){
//                 inDegree[neigh]++;
//             }
//         }

//         //outdegree for each vertex:
//         vector<int> outDegree(n+1,0);
//         for(int i=1;i<=n;i++){
//             outDegree[i]=adj[i].size();

//         }
//         for(int i=1;i<=n;i++){
//            if(inDegree[i]==n-1 && outDegree[i]==0){
//                return i;
//             }
//         }
//         return -1;

//     }
// };

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1,0);
        for(auto &neigh:trust){
            int u=neigh[0];
            int v=neigh[1];
            score[u]--;
            score[v]++;

        }
        for(int i=1;i<=n;i++){
            if(score[i]==n-1) return i;
        }
        return -1;
    }
};