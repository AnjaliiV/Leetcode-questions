class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,-1));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        if(q.empty() || q.size()==n*n) return -1;
        int ans=0;
        while(!q.empty()){   
            int x=q.front().first;
            int y=q.front().second;
            q.pop();     
             for(auto &d:dir){
                 int nx=x+d[0];
                 int ny=y+d[1];
                 if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[x][y]+1;
                    ans=max(ans,dist[nx][ny]);
                    q.push({nx,ny});
                 }
            }
        }
        return ans;
       
    }
};