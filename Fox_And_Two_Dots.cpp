#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isCycle(int sx, int sy, vector<vector<char>> &grid, vector<vector<bool>> &visited){
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{sx, sy}, {-1, -1}});
    visited[sx][sy] = true;

    while(!q.empty()){
        auto cur = q.front(); 
        q.pop();
        int x  = cur.first.first;
        int y  = cur.first.second;
        int px = cur.second.first;
        int py = cur.second.second;

        for(auto &d : dir){
            int nx = x + d[0];
            int ny = y + d[1];

            if(!valid(nx, ny)) continue;
            if(grid[nx][ny] != grid[x][y]) continue;

            if(visited[nx][ny]){
                if(nx != px || ny != py) return true;
            }
            else{
                visited[nx][ny] = true;
                q.push({{nx, ny}, {x, y}});
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                if(isCycle(i,j,grid,visited)){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}
