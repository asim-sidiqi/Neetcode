class Solution {
private:
    int solve(int r, int c, int& row, int& col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(r==row-1 && c==col-1) return grid[r][c];

        if(r>=row || c>=col) return INT_MAX;

        if(dp[r][c]!=-1) return dp[r][c];
        int bot = solve(r+1, c, row, col, grid, dp);
        int rig = solve(r, c+1, row, col, grid, dp);

        int mini = min(bot,rig);

        if(mini == INT_MAX)
            return INT_MAX;

        return dp[r][c] = grid[r][c] + mini;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        return solve(0,0,row,col,grid,dp);
    }
};