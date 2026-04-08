class Solution {
private:
    int solve(int idx, int n, vector<int>& cost, vector<int>& dp){
        if(idx >= n) return 0;

        if(idx!=-1 && dp[idx]!=-1) return dp[idx];

        int oneStep = solve(idx+1, n, cost, dp);
        int twoStep = solve(idx+2, n, cost, dp);

        if(idx == -1) return min(oneStep, twoStep);

        return dp[idx] = cost[idx] + min(oneStep, twoStep);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(-1, n, cost, dp);
    }
};