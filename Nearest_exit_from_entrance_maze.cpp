class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int a=entrance[0];
        int b=entrance[1];
        q.push({a,b});
        dist[a][b]=0;
        visited[a][b]=1;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]=='.' && !visited[nx][ny]){
                    dist[nx][ny]=dist[x][y]+1;
                    if((nx==0 || nx==n-1 || ny==0 || ny==m-1) && !(nx==entrance[0] && ny==entrance[1])){
                        return dist[nx][ny];
                    }
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};