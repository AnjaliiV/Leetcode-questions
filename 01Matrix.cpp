class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){   
            int x=q.front().first;
            int y=q.front().second;
            q.pop();     
            //check in all directions:
             for(auto &d:dir){
                 int nx=x+d[0];
                 int ny=y+d[1];
                 // now all the pushed 0 will check for out of bound and if they find 1 to them
                 if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                 }
            }
        }
        return dist;
    }
};