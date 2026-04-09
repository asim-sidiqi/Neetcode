class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];

        int mini = INT_MAX;
        for(int i=1; i*i<=n; i++){ 
            int r = 1+solve(n-i*i,dp);
            mini = min(mini, r);
        }

        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        //return solve(n,dp);

        dp[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }

        return dp[n];
    }
};