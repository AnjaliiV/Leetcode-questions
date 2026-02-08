// User function Template for C++

class Solution {
  public:
  vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<bool>> visited(N,vector<bool>(M,0));
        if(X==0 && Y==0) return 0; //if source=dest
        if(A[0][0]==0) return -1; //source is 0
        queue<pair<int,pair<int,int>>> q;
        visited[0][0]=1;
        q.push({0,{0,0}});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second.first;
            int steps=q.front().second.second;
            q.pop();
            for(auto &d:dir){
                int nx=row+d[0];
                int ny=col+d[1];
                
                if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1 && !visited[nx][ny]){
                    if(nx==X && ny==Y) return steps+1;
                    visited[nx][ny]=1;
                    q.push({nx,{ny,steps+1}});
                }
            }
        }
        return -1;
    }
};