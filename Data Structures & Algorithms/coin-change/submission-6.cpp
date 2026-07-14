class Solution {
private:
    int solve(int idx, int n, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(amount<=0 || idx>=n) return INT_MAX;

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int l = solve(idx, n, coins, amount-coins[idx], dp);
        if(l != INT_MAX) l += 1;
        int r = solve(idx+1, n, coins, amount, dp);

        return dp[idx][amount] = min(l,r);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1, -1));
        int ans = solve(0, n, coins, amount, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
