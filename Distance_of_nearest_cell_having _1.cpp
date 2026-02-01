class Solution {
  public:
  int n,m;
  vector<vector<int>> dir={{1,0},{-1,0},{0,1,},{0,-1}};
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
    n=grid.size();
    if(n==0) return {};
    m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(auto &d:dir){
              int nx=x+d[0];
              int ny=y+d[1];
              if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){
                  dist[nx][ny]=dist[x][y]+1;
                  q.push({nx,ny});
              }
        }

        }
        return dist;

    }
};

