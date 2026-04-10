class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(m<0 || n<0) return 0;
        if(grid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;

        if(dp[m][n]!=-1) return dp[m][n];

        int l = solve(m-1,n,grid, dp);
        int r = solve(m,n-1,grid, dp);

        return dp[m][n] = l+r;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        //return solve(m-1, n-1, obstacleGrid, dp);

        //tabulation

        dp[0][0]=1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) continue;
                int l = i>0 ? dp[i-1][j] : 0;
                int r = j>0 ? dp[i][j-1] : 0;

                dp[i][j] = l+r;
            }
        }

        return dp[m-1][n-1];
    }
};