class Solution {
public:
    // int dp[101][101]; M-1
    int m,n;
    // int helper(int i, int j, vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
    //     // Base Case:
    //     if( i>=m  || j>=n || obstacleGrid[i][j]) return 0;
        
    //     if(i==m-1 && j==n-1 ) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     // Down move:
    //     int down=helper(i+1, j,dp,obstacleGrid);

    //     // Right move:
    //     int right=helper(i,j+1,dp,obstacleGrid);

    //     return dp[i][j]=right+ down;
    // }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         m=obstacleGrid.size();
         n=obstacleGrid[0].size();
        // memset(dp,-1,sizeof(dp)); M-1
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return helper(0,0,dp,obstacleGrid);
        // Tabulation:
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0]=1;
        // Fill the first row
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]!=1)
            dp[0][j]=dp[0][j-1];
        }

        //Fill the first column
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]!=1)
            dp[i][0]=dp[i-1][0];
        }


       for(int i=1;i<m;i++){
          for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1) dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
    }
};
