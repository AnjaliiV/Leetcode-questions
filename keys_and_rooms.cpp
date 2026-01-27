class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> q;
        vector<bool>visited(n,0);
        int st=0;
        q.push(st);
        visited[st]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<rooms[node].size();j++){
               if(!visited[rooms[node][j]]){
                   q.push(rooms[node][j]);
                   visited[rooms[node][j]]=1;
               }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false)
            return 0;
        }
        return 1;
    }
};