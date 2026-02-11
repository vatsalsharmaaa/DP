class Solution {
public:
    int m,n;
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>&grid){
        if(grid[n-1][m-1]==1){
            return dp[i][j]=0;
        }
        if(i==n-1 && j==m-1){
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<0 || j<0 ||i>=n ||j>=m||grid[i][j]==1){
            return dp[i][j]= 0;
        }
        int right=solve(i+1,j,grid);
        int down=solve(i,j+1,grid);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        memset(dp,-1,sizeof(dp));
        m=obstacleGrid[0].size();
        return solve(0,0,obstacleGrid);
    }
};