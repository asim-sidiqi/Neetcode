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

        return solve(m-1, n-1, obstacleGrid, dp);
    }
};